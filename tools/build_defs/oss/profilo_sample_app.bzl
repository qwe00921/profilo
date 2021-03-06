"""
Provides some helpers for defining Profilo sample apps.

profilo_sample_app - Helper wrapper for defining a sample app with a given set of providers

PROVIDER_TO_RULE - Map that links provider "short names" to the provider class and dependency.
                   Can be extended in individual BUCK files to add more providers specific to
                   those files.
"""

load("//tools/build_defs/android:fb_core_android_library.bzl", "fb_core_android_library")
load("//tools/build_defs/oss:profilo_defs.bzl", "profilo_path")

PROVIDER_TO_RULE = {
    "atrace": profilo_path("java/main/com/facebook/profilo/provider/atrace:atrace"),
    "mappingdensity": profilo_path("java/main/com/facebook/profilo/provider/mappingdensity:mappingdensity"),
    "processmetadata": profilo_path("java/main/com/facebook/profilo/provider/processmetadata:processmetadata"),
    "stacktrace": profilo_path("java/main/com/facebook/profilo/provider/stacktrace:stacktrace"),
    "systemcounters": profilo_path("java/main/com/facebook/profilo/provider/systemcounters:systemcounters"),
    "threadmetadata": profilo_path("java/main/com/facebook/profilo/provider/threadmetadata:threadmetadata"),
    "yarn": profilo_path("java/main/com/facebook/profilo/provider/yarn:yarn"),
}

def profilo_sample_app(srcs, app_manifest, aar_manifest, providers, deps = [], provider_to_rule = PROVIDER_TO_RULE):
    """
    Defines a sample app based on a list of provider short names.

    Creates AAR and APK rules named `sample-[aar-]{providers[0]}-{providers[1]}-{etc}`.
    If providers is empty or None, creates `sample-[aar-]-none`.

    Args:
        srcs:          Top-level java files. Should include, at least, a concrete
                       implementation of BaseSampleAppMainActivity.
        app_manifest:  The manifest file, or target, to use for your sample app.
        aar_manifest:  The manifest file, or target, to use for the associated aar targets
        providers:     A list of valid entry keys in PROVIDER_TO_RULE, or None.
        deps:          Any extra dependencies your java files use. Provider dependencies, as well
                       as `profilo_path("java/main/com/facebook/profilo/core:core")` (for
                       `BaseTraceProvider`), will be automatically added and do not
                       need to be listed.
    """
    if providers:
        providers = sorted(providers)
        providers_string = "-".join(providers)
        provider_deps = [provider_to_rule[provider] for provider in providers]
    else:
        providers_string = "none"
        provider_deps = []

    native.android_build_config(
        name = "sample-buildconfig-{}".format(providers_string),
        package = "com.facebook.profilo",
        values = [
            "String[] PROVIDERS = new String[] {{ {} }}".format(
                ",".join(["\"{}\"".format(provider) for provider in (providers if providers else [])]),
            ),
        ],
    )

    # We want all providers on the compile path but only package the ones that
    # the current config enables. However, the provided_deps take precedence
    # and targets specified in both provided and normal deps will be elided.
    #
    # Therefore, calculate the difference between the full set and the enabled
    # set and put only that in the provided list.

    provided_deps = [
        x
        for x in provider_to_rule.values()
        if x not in provider_deps
    ]

    fb_core_android_library(
        name = "sample-providers-{}".format(providers_string),
        visibility = [
            profilo_path("..."),
        ],
        exported_deps = [
            profilo_path("java/main/com/facebook/profilo/core:core"),
        ] + provider_deps + deps,
    )

    fb_core_android_library(
        name = "sample-activity-{}".format(providers_string),
        srcs = srcs,
        provided_deps = provided_deps,
        visibility = [
            profilo_path("..."),
        ],
        deps = [
            ":sample-providers-{}".format(providers_string),
            profilo_path("java/main/com/facebook/profilo/sample:sample-lib"),
        ],
    )

    native.android_aar(
        name = "sample-aar-{}".format(providers_string),
        manifest_skeleton = aar_manifest,
        deps = [
            ":sample-providers-{}".format(providers_string),
            profilo_path("java/main/com/facebook/profilo/config:config"),
            profilo_path("java/main/com/facebook/profilo/controllers/external:external"),
            profilo_path("java/main/com/facebook/profilo/controllers/external/api:api"),
            profilo_path("java/main/com/facebook/profilo/core:core"),
            profilo_path("deps/soloader:soloader"),
        ],
        visibility = [
            "PUBLIC",
        ],
    )

    native.android_binary(
        name = "sample-{}".format(providers_string),
        keystore = profilo_path("java/main/com/facebook/profilo/sample:keystore"),
        manifest = app_manifest,
        deps = [
            ":sample-buildconfig-{}".format(providers_string),
            ":sample-activity-{}".format(providers_string),
        ],
        aapt_mode = "aapt2",
    )

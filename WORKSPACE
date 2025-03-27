load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "pybind11_bazel",
  strip_prefix = "pybind11_bazel-34206c29f891dbd5f6f5face7b91664c2ff7185c",
  urls = ["https://github.com/pybind/pybind11_bazel/archive/34206c29f891dbd5f6f5face7b91664c2ff7185c.zip"],
  sha256 = "8d0b776ea5b67891f8585989d54aa34869fc12f14bf33f1dc7459458dd222e95",
)

http_archive(
  name = "pybind11",
  build_file = "@pybind11_bazel//:pybind11.BUILD",
  strip_prefix = "pybind11-a54eab92d265337996b8e4b4149d9176c2d428a6",
  urls = ["https://github.com/pybind/pybind11/archive/a54eab92d265337996b8e4b4149d9176c2d428a6.tar.gz"],
  sha256 = "c9375b7453bef1ba0106849c83881e6b6882d892c9fae5b2572a2192100ffb8a",
)
load("@pybind11_bazel//:python_configure.bzl", "python_configure")
python_configure(name = "local_config_python")

http_archive(
    name = "com_google_protobuf",
    sha256 = "f66073dee0bc159157b0bd7f502d7d1ee0bc76b3c1eac9836927511bdc4b3fc1",
    strip_prefix = "protobuf-3.21.9",
    urls = [
        "http://localhost:8100/protobuf_v3.21.9.zip",
        "https://storage.googleapis.com/mirror.tensorflow.org/github.com/protocolbuffers/protobuf/archive/v3.21.9.zip",
        "https://github.com/protocolbuffers/protobuf/archive/v3.21.9.zip",
    ],
)
load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

http_archive(
    name = "rules_cc",
    sha256 = "cf3b76a90c86c0554c5b10f4b160f05af71d252026b71362c4674e2fb9936cf9",
    strip_prefix = "rules_cc-01d4a48911d5e7591ecb1c06d3b8af47fe872371",
    urls = [
        "http://localhost:8100/rules_cc_01d4a48911d5e7591ecb1c06d3b8af47fe872371.zip",
        "https://storage.googleapis.com/mirror.tensorflow.org/github.com/bazelbuild/rules_cc/archive/01d4a48911d5e7591ecb1c06d3b8af47fe872371.zip",
        "https://github.com/bazelbuild/rules_cc/archive/01d4a48911d5e7591ecb1c06d3b8af47fe872371.zip",
    ],
)

http_archive(
    name = "rules_proto",
    sha256 = "2490dca4f249b8a9a3ab07bd1ba6eca085aaf8e45a734af92aad0c42d9dc7aaf",
    strip_prefix = "rules_proto-218ffa7dfa5408492dc86c01ee637614f8695c45",
    url = "https://mirrors.tencent.com/github.com/bazelbuild/rules_proto/archive/218ffa7dfa5408492dc86c01ee637614f8695c45.tar.gz",
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

http_archive(
    name = "rules_python",
    sha256 = "ca77768989a7f311186a29747e3e95c936a41dffac779aff6b443db22290d913",
    strip_prefix = "rules_python-0.36.0",
    url = "https://github.com/bazel-contrib/rules_python/releases/download/0.36.0/rules_python-0.36.0.tar.gz",
)
load("@rules_python//python:repositories.bzl", "py_repositories")
py_repositories()
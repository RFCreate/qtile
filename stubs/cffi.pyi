from typing import List  # noqa: F401

__version_info__ = ...  # type: List

class FFI:
    def cdef(self, csource, override=False, packed=False): ...
    def compile(self, tmpdir=".", verbose=0, target=None, debug=None): ...
    def include(self, ffi_to_include): ...
    def set_source(self, module_name, source, source_extension=".c", **kwargs): ...

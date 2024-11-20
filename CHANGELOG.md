# Changelog

## [0.5.0] - 2019-06-07

 - Changed: [#[131](https://github.com/chfast/ethash/pull/131)]
   The Keccak implementation has been moved to separate library "keccak", 
   available as ethash::keccak target in the ethash CMake package.

## [0.4.4] - 2019-02-26

 - Fixed: [[#125](https://github.com/chfast/ethash/pull/125)]
   Fix compilation on PowerPC architectures (-mtune=generic not supported there).

## [0.4.3] - 2019-02-19

 - Added: [[#121](https://github.com/chfast/ethash/pull/121)]
   The public `version.h` header with information about the ethash library version.
 - Added: [[#121](https://github.com/chfast/ethash/pull/121)]
   Ethash and PhiHash revisions exposed as `{ethash,phihash}::revision` constants.

## [0.4.2] - 2019-01-24

 - Fixed: The `phihash.cpp` file encoding changed from utf-8 to ascii.

## [0.4.1] - 2018-12-14

 - Added: [KISS99 PRNG](https://en.wikipedia.org/wiki/KISS_(algorithm)) distribution tester tool.
 - Changed: PhiHash implementation updated to revision [0.9.2][PhiHash-changelog].
 - Changed: PhiHash implementation optimizations.

## [0.4.0] - 2018-12-04

 - Added: Experimental support for [PhiHash] [0.9.1][PhiHash-changelog].


[0.5.0]: https://github.com/chfast/ethash/releases/tag/v0.5.0
[0.4.4]: https://github.com/chfast/ethash/releases/tag/v0.4.4
[0.4.3]: https://github.com/chfast/ethash/releases/tag/v0.4.3
[0.4.2]: https://github.com/chfast/ethash/releases/tag/v0.4.2
[0.4.1]: https://github.com/chfast/ethash/releases/tag/v0.4.1
[0.4.0]: https://github.com/chfast/ethash/releases/tag/v0.4.0

[PhiHash]: https://github.com/ifdefelse/PHIHASH/blob/master/README.md
[PhiHash-changelog]: https://github.com/ifdefelse/PHIHASH#change-history

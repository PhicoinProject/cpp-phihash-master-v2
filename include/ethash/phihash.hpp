// ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
// Copyright 2018-2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

/// @file
///
/// PhiHash API
///
/// This file provides the public API for PhiHash as the Ethash API extension.

#include <ethash/ethash.hpp>

namespace phihash
{
using namespace ethash;  // Include ethash namespace.


/// The PhiHash algorithm revision implemented as specified in the spec

constexpr auto revision = "2.0.1";

constexpr int period_length = 3;
constexpr uint32_t num_regs = 32;
constexpr size_t num_lanes = 16;
constexpr int num_cache_accesses = 11;
constexpr int num_math_operations = 18;
constexpr size_t l1_cache_size = 16 * 1024;
constexpr size_t l1_cache_num_items = l1_cache_size / sizeof(uint32_t);

result hash(const epoch_context& context, int block_number, const hash256& header_hash,
    uint64_t nonce) noexcept;

result hash(const epoch_context_full& context, int block_number, const hash256& header_hash,
    uint64_t nonce) noexcept;

bool verify(const epoch_context& context, int block_number, const hash256& header_hash,
    const hash256& mix_hash, uint64_t nonce, const hash256& boundary) noexcept;

//bool light_verify(const char* str_header_hash,
//        const char* str_mix_hash, const char* str_nonce, const char* str_boundary, char* str_final) noexcept;

search_result search_light(const epoch_context& context, int block_number,
    const hash256& header_hash, const hash256& boundary, uint64_t start_nonce,
    size_t iterations) noexcept;

search_result search(const epoch_context_full& context, int block_number,
    const hash256& header_hash, const hash256& boundary, uint64_t start_nonce,
    size_t iterations) noexcept;

}  // namespace phihash

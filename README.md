# PhiHash: ASIC-Resistant Mining Algorithm for Phicoin

![License](https://img.shields.io/badge/license-Apache%202.0-blue.svg)
![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Version](https://img.shields.io/badge/version-2.0.0-orange.svg)

## Overview

PhiHash is an advanced proof-of-work mining algorithm specifically designed for Phicoin cryptocurrency. Built upon the foundation of **KawPow** and **ProgPoW** algorithms, PhiHash incorporates innovative ASIC-resistance mechanisms based on **[Huang's Law](https://en.wikipedia.org/wiki/Huang%27s_law)** to ensure fair and decentralized mining.

### Key Features

- 🛡️ **ASIC-Resistant**: Dynamic memory requirements that grow 25% annually
- 🚀 **GPU-Optimized**: Leverages modern GPU capabilities for efficient mining  
- 📈 **Huang's Law Compliance**: Memory scaling follows GPU performance trends
- 🔒 **Secure**: Cryptographically robust with multiple hash functions
- ⚡ **Efficient**: Optimized for both performance and energy consumption

## Algorithm Specifications

| Parameter | Value | Description |
|-----------|-------|-------------|
| **Base Memory Size** | 4GB | Initial dataset size at genesis |
| **Annual Growth Rate** | 25% | Memory increases following Huang's Law |
| **Hash Function** | Keccak-256 | Primary cryptographic hash |
| **DAG Generation** | Ethash-based | Directed Acyclic Graph construction |
| **Cache Size** | 64MB | Light client cache size |
| **Epoch Length** | 2102400 blocks | Period between difficulty adjustments |

## Huang's Law Integration

PhiHash is the first mining algorithm to implement **Huang's Law** principles in cryptocurrency mining:

> *"The performance of GPUs will more than double every two years"* - Jensen Huang, NVIDIA CEO

### How It Works

1. **Memory Scaling**: Dataset size increases by 25% annually
2. **GPU Advantage**: Memory growth matches GPU development trends  
3. **ASIC Deterrent**: Rapidly changing memory requirements make ASIC development economically unfeasible
4. **Future-Proof**: Algorithm adapts to hardware evolution automatically

```
Year 0: 4.0 GB  
Year 1: 5.0 GB (+25%)
Year 2: 6.25 GB (+25%)
Year 3: 7.8 GB (+25%)
...
```

## Installation

### Prerequisites

- **CMake** 3.5 or higher
- **C++11** compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- **OpenCL** or **CUDA** development libraries (for GPU mining)

### Building from Source

```bash
# Clone the repository
git clone https://github.com/PhicoinProject/cpp-phihash-master-v2.git
cd phihash

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Compile
make -j$(nproc)

# Install (optional)
sudo make install
```

### Build Options

| Option | Description | Default |
|--------|-------------|---------|
| `ETHASH_BUILD_TESTS` | Build unit tests | ON |
| `ETHASH_NATIVE` | Optimize for native CPU | OFF |
| `ETHASH_FUZZING` | Enable fuzzer instrumentation | OFF |

## Usage

### C++ Integration

```cpp
#include <ethash/phihash.hpp>

// Initialize epoch context
auto context = ethash::create_epoch_context(epoch_number);

// Calculate hash
auto result = phihash::hash(*context, block_number, header_hash, nonce);

// Verify result
bool valid = phihash::verify(*context, block_number, header_hash, 
                           result.mix_hash, nonce, boundary);
```

### Python Bindings

```python
import phihash

# Create mining context
context = phihash.create_context(epoch=0)

# Mine a block
result = phihash.hash(context, block_number=1000, 
                     header=b'0x...', nonce=12345)

print(f"Final hash: {result.final_hash.hex()}")
print(f"Mix hash: {result.mix_hash.hex()}")
```

## Technical Architecture

### Algorithm Components

1. **Keccak Hashing**: Primary cryptographic function
2. **DAG Generation**: Memory-hard dataset construction  
3. **Random Math Operations**: 11 different mathematical operations including:
   - Arithmetic: Add, Multiply, Subtract
   - Bitwise: AND, OR, XOR, Rotate
   - Statistical: Min, Max
   - Advanced: Hyperbolic tangent mixing
4. **Memory Access Patterns**: Randomized cache and dataset access

### Memory Layout

```
┌─────────────────┐
│   Light Cache   │ 64MB (shared)
├─────────────────┤
│   L1 Cache      │ 16KB (per thread)  
├─────────────────┤
│   Full Dataset  │ 4GB+ (grows 25%/year)
└─────────────────┘
```

## ASIC Resistance Strategy

### Why ASICs Struggle with PhiHash

1. **Dynamic Memory**: Annual 25% increase makes ASIC design obsolete quickly
2. **Complex Operations**: 11 different math operations require versatile hardware
3. **Random Access Patterns**: Unpredictable memory access defeats specialized circuits
4. **GPU Advantage**: Algorithm designed to leverage GPU parallel architecture


## Security Features

- **256-bit Security**: Full SHA-3/Keccak-256 strength
- **Quantum Resistant**: Hash-based security model
- **Collision Resistant**: Cryptographically secure design
- **Pre-image Resistant**: One-way hash function properties

## Roadmap

- [x] **v1.0**: Initial PhiHash implementation
- [x] **v2.0**: Huang's Law integration  
- [ ] **v2.1**: Performance optimizations


## Contributing

We welcome contributions! Please see our [Contributing Guidelines](CONTRIBUTING.md) for details.

### Development Setup

```bash
# Install development dependencies
sudo apt-get install cmake build-essential opencl-headers

# Build with tests
mkdir build && cd build
cmake .. -DETHASH_BUILD_TESTS=ON
make -j$(nproc)

# Run tests
./test/ethash-test
```

## Community & Support

- 📧 **Email**: dev@phicoin.org
- 💬 **Discord**: [Phicoin Community](https://discord.gg/phicoin)
- 🐛 **Issues**: [GitHub Issues](https://github.com/PhicoinProject/cpp-phihash-master-v2/issues)

## License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details.

## Citations

If you use PhiHash in academic research, please cite:

```bibtex
@software{phihash2024,
  title={PhiHash: ASIC-Resistant Mining Algorithm Based on Huang's Law},
  author={Phicoin Development Team},
  year={2024},
  url={https://github.com/PhicoinProject/cpp-phihash-master-v2}
}
```

## Acknowledgments

- **Ethereum Foundation** - For the original Ethash algorithm
- **ProgPoW Team** - For ASIC-resistance innovations  
- **NVIDIA** - For GPU computing advancement (Huang's Law)
- **Open Source Community** - For continuous improvements and feedback

---

*PhiHash: Ensuring decentralized mining through innovative ASIC resistance.* 

# Secure C++ Code Review Showcase  
**Demonstrating Memory Corruption Vulnerabilities & Remediation**  
*(CWE-119: Improper Restriction of Operations within the Bounds of a Memory Buffer & CWE-416: Use After Free)*

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++ Standard](https://img.shields.io/badge/C%2B%2B-11%2B-blue)](https://isocpp.org/)
[![SonarQube](https://img.shields.io/badge/Analysis-SonarQube-4E9F70)](https://www.sonarsource.com/products/sonarqube/)

This repository serves as a **portfolio showcase** for Application Security (AppSec) engineers. It illustrates the **secure code review lifecycle** in C++:  
- Identifying classic memory corruption vulnerabilities (buffer overflows & use-after-free)  
- Performing static analysis with **SonarQube**  
- Applying modern C++ mitigations (RAII, smart pointers, safe APIs)  
- Documenting root causes, exploits, and remediation strategies  

All examples are **minimal, educational, and deliberately vulnerable** — never use them in production!

## 🎯 Project Goals

- Demonstrate **CWE-119** (buffer overflow / out-of-bounds access) and **CWE-416** (use-after-free) in modern C++  
- Show the power of **static application security testing (SAST)** using SonarQube (AST-based analysis)  
- Compare **vulnerable** vs **secure** implementations side-by-side  
- Highlight DevSecOps best practices: separation of concerns, versioned remediation, and auditability  
- Serve as a learning resource for developers and security professionals

## 📂 Repository Structure

```text
.
├── .github/                # GitHub Actions workflows (CI/CD for scans)
├── analysis/               # SonarQube reports, scan results, screenshots
├── builds/                 # CMakeLists.txt, build scripts, compilation configs
├── docs/                   # Detailed theoretical explanations, CWE mappings, threat models
├── vulnerable/             # Intentionally flawed code examples (isolated snippets)
│   └── src/
├── secure/                 # Remediated, production-ready versions (RAII/smart pointers)
│   └── src/
├── tests/                  # Unit tests / harnesses to verify behavior (crash vs safe)
├── sonar-project.properties # SonarQube configuration
├── README.md               # This file
└── SECURITY.md             # Security policy & responsible disclosure guidelines
```

## ⚠️ Important Security & Ethical Notes

- **This is educational only** — code is deliberately vulnerable for learning purposes.  
- **Do NOT run vulnerable binaries in untrusted environments** (use VMs/containers with no network).  
- All examples are minimal and contain **no real exploits/shellcode**.  
- Inspired by/adapted from public resources (Mitre CWE, open-source vulnerable snippets) with proper attribution in docs/.  
- Follows ethical guidelines for vulnerability demonstration (no live exploits, no production harm).

## 🔍 Vulnerabilities Covered

### CWE-119: Buffer Overflow / Improper Bounds Checking
**Root cause**: Unsafe functions (`strcpy`, `memcpy`) without length validation on fixed-size buffers.  
**Impact**: Stack/heap corruption → potential control-flow hijacking (ROP, code execution).  
**Mitigation**: `std::string`, `std::span`, `strncpy` + checks, bounds-checked containers.

### CWE-416: Use After Free
**Root cause**: Accessing memory after `delete`/`free` (dangling pointers), leading to reallocation abuse.  
**Impact**: Data corruption, double-free, heap spraying → arbitrary code execution.  
**Mitigation**: `std::unique_ptr`, `std::shared_ptr`, RAII, nullification after free.

## 🛠️ How to Use / Explore This Repo

1. **Clone the repository**
   ```bash
   git clone https://github.com/YOUR-USERNAME/secure-cpp-code-review.git
   cd secure-cpp-code-review
   ```

2. **Build & Run Vulnerable Examples** (use caution!)
   ```bash
   mkdir build && cd build
   cmake ../builds
   make
   # Run carefully (e.g. in Docker)
   ./vulnerable/buffer_overflow_demo
   ```

3. **Run SonarQube Analysis** (recommended!)
   - Start local SonarQube (Docker recommended):
     ```bash
     docker run -d -p 9000:9000 --name sonarqube sonarsource/sonarqube:lts-community
     ```
   - Analyze:
     ```bash
     sonar-scanner
     ```
   - Open http://localhost:9000 → view hotspots, bugs, vulnerabilities

4. **Compare Vulnerable vs Secure**
   - Diff `vulnerable/src/` vs `secure/src/` to see remediation diffs  
   - Check `docs/` for in-depth explanations

## 🧰 Tools & Technologies Used

- **Language**: C++11+ (modern safe practices)  
- **Build**: CMake  
- **Static Analysis**: SonarQube (C-family analyzer, AST-based)  
- **Testing**: Catch2 / GoogleTest (optional)  
- **CI/CD**: GitHub Actions (planned: auto-scan on push)

## 📚 Learning Resources & Attribution

- Mitre CWE: [CWE-119](https://cwe.mitre.org/data/definitions/119.html), [CWE-416](https://cwe.mitre.org/data/definitions/416.html)  
- SANS Top 25, OWASP SAMM, DevSecOps principles  
- SonarSource documentation & C++ analysis guides  
- Inspirations: public vulnerable code collections (adapted & credited in docs/)


---

**Happy secure coding!** 🛡️  
Built with ❤️ by an AppSec Engineer passionate about memory safety in C++.

# Blockchain-Based Login System

This project implements a Blockchain-based login system running on a local blockchain. The system leverages blockchain technology for secure and decentralized authentication. It includes various components that handle blockchain building, cryptography, password security, terminal-based UI, and user management, all written in C.

## Table of Contents

- [Project Overview](#project-overview)
- [Key Components](#key-components)
- [Technology Stack](#technology-stack)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

The Blockchain-Based Login System is designed to provide a secure, decentralized way to manage user authentication using a local blockchain. By employing cryptographic functions and blockchain immutability, this system ensures high-level security for user credentials and login processes.

## Key Components

1. **Blockchain Build Code**  
   Responsible for setting up and managing the blockchain on which the login data is stored.
   
2. **Crypto Utilities**  
   Cryptographic functions used for hashing passwords and other sensitive data.

3. **Password Security Code**  
   Ensures the security of user passwords through cryptographic hashing and salting techniques.
   
4. **Terminal UI Code**  
   A terminal-based user interface that allows users to interact with the system and perform operations like registration and login.
   
5. **User Management Code**  
   Handles user registration, login, and other user-related operations.

6. **Header Files**  
   Include all necessary function prototypes and declarations for the system.

7. **Main Code**  
   The core code that integrates all the components and runs the system.

## Technology Stack

- **Programming Language**: C
- **Blockchain**: Local implementation of a simple blockchain
- **Cryptography**: Secure hashing algorithms for password management
- **User Interface**: Terminal-based UI

## Getting Started

### Prerequisites

Make sure you have the following tools installed on your machine:

- **C Compiler**: GCC or Clang
- **Make** (Optional but recommended for compiling the project)

### Installation

- **Clone the Repo**
- **In terminal run the make command**
    ```bash
    make
    ```
- **For Cleaning the object .o files**
   ```bash
   make clean
   ```
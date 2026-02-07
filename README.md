# Intruder-BruteForce-Sim
A C-based tool demonstrating numeric brute-force attacks and O(N) complexity
Intruder v3 – Brute-Force PIN Logic (Foundational Security Study)
Overview

Intruder v3 is a standalone C program that simulates a numeric PIN brute-force attack (0000–9999).
It was built as a foundational security exercise to understand how authentication brute-force attacks work at a logical and implementation level, rather than relying solely on automated tools.

This project complements my penetration testing practice and reporting by focusing on how vulnerabilities emerge from code and logic decisions.

Context & Motivation

During penetration testing labs and CTFs, I found that many authentication vulnerabilities are explained at a high level but rarely explored from the perspective of how the attack logic actually operates.

This project was created to:

demystify brute-force tooling,

reinforce how authentication logic behaves internally,

and strengthen my ability to reason about vulnerabilities while testing and reporting.

Writing this program in C was a deliberate choice to stay close to low-level logic, input handling, and control flow—skills that directly translate to analyzing real-world backend implementations.

What the Program Demonstrates

The program:

Accepts a target PIN via standard input

Iterates through the full PIN keyspace (0000–9999)

Normalizes PIN formatting (e.g. 0001, not 1)

Simulates request pacing with delays

Terminates immediately upon a successful match

Displays progress and results clearly in the terminal

Conceptually, this mirrors how tools automate:

PIN brute-force attacks

OTP guessing

authentication enumeration

Security Concepts Reinforced

This project reinforces concepts that frequently appear in penetration testing reports:

Brute-force attack mechanics

Input validation and boundary enforcement

Rate limiting and request pacing

Early-exit conditions and information leakage

Data normalization issues ("1" vs "0001")

Assumption failures in authentication logic

These same concepts are applied and documented in my penetration testing reports when identifying and explaining authentication-related findings.

Relationship to Pentest Reporting

This project supports my pentesting workflow by strengthening the thinking behind findings, not just execution.

It helps me:

identify where brute-force protections are missing or flawed,

understand why an attack is possible before attempting it,

and clearly explain impact, reproduction steps, and root causes in reports.

Rather than treating tools as black boxes, this project builds intuition that feeds directly into structured pentest documentation.

Compilation & Execution
clang intruder_v3.c -o intruder
./intruder


Follow the prompt to enter a target PIN.

Ethical Use Notice

This program is intended strictly for educational and authorized testing purposes.
It exists to demonstrate foundational security concepts and should not be used against real systems without permission.

Author’s Note

This project was built alongside penetration testing labs and CTF reporting as part of a focused effort to strengthen foundational understanding of how vulnerabilities arise in real systems.

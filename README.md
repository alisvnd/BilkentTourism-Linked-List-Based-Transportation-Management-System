# BilkentTourism-Linked-List-Based-Transportation-Management-System
This project implements BilkentTourism, a transportation management system that models bus lines, stops, and buses using sorted linked lists only. Each entity (bus line, stop, bus) is uniquely identified by its own ID space, and all operations strictly preserve sorted order.

The system supports:

Managing bus lines with unique IDs and names

Managing stops, which can be shared across multiple lines

Assigning and unassigning buses to specific lines

Querying which buses pass through a given stop

All data structures are implemented using custom singly linked lists, without using arrays, vectors, or STL containers. Each bus line maintains its own sorted list of stops and buses, while the system globally tracks all lines and stops in ascending order by ID.

The project focuses heavily on:

Pointer-based data structure design

Dynamic memory management (no memory leaks)

Sorted insertion and deletion

Cross-linked relationships between entities (stops shared by multiple lines)

Strict output formatting to match predefined specifications

The implementation includes comprehensive error handling for invalid operations such as duplicate IDs, non-existent entities, and attempts to remove stops currently in use. The system is designed to scale dynamically and supports complex queries like listing all buses passing through a specific stop across different lines.

This project demonstrates strong proficiency in linked lists, object-oriented design in C++, manual memory management, and robust system-level programming.

Problem Statement:
Imagine you are a Data Structure Architect and As a Data Structure Architect, your objective is to design and implement a specialized data structure in C++ for managing the marks of up to n students. This data structure will be utilized by programmers to perform a variety of operations efficiently. The data structure must adhere to the following functional requirements:

1.Tracking the Number of Stored Elements:
Implement a mechanism to precisely track and retrieve the number of marks currently stored in the data structure.

2.Insertion of an Element at a Specific Index:
Provide functionality to insert a new mark at a specified index without overwriting existing data. For example, if 19 marks are stored and a programmer needs to insert a mark at index 2, the insertion must preserve all existing data.

3.Handling Overflow and Underflow Conditions:
Incorporate safeguards to prevent:

4.Overflow: When attempting to insert marks beyond the array's capacity (n elements).
5.Underflow: When attempting to remove marks from an empty data structure.

6.Validation of Data Integrity:
Provide a mechanism to determine whether the data at any given index is valid or uninitialized, ensuring that operations only process meaningful data.

7.Deletion of an Element at a Specified Index:
Define an efficient process for deleting a mark at a specified index while maintaining the integrity and order of the remaining data.

Your C++ implementation must encapsulate these functionalities, ensuring modularity, safety, and ease of use for programmers.
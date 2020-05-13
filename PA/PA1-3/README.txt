Name: Minh Luu

UIN: 424004602

==========================================AGGIE HONOR STATEMENT==========================================
I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
=========================================================================================================

Source(s) for this assignment:
- Geeksforgeeks.org
- Brilliant.org
- Khanacademy.org
- All 4 PTs

Known problems with my code: None


Description: The Collection class can now take in any class that is similar to Stress ball and its
             functionalities will still work as expected thanks to class template. This is called
             generic programming.

About generic programming:
- Definition:   Generic programming refers to a style of computer programming in which algorithms are
                written in terms of types to-be-specified-later that are then instantiated when needed 
                for specific types provided as parameters. 
- This program: This assignment is a modification of PA1-2. By adding class template to Collection, we 
                are able to put any arbitrary class that has similar characteristics to Stress_ball
                and still get the same expected results. In this case, the Jeans class has similar
                attributes and when I used it with the Collection template, everything worked without 
                any further tweaking.
- Further:      Sometimes, you need a class implementation that is same for all classes, only the data types
                used are different. This is when generic programming comes in. It is implemented to increase 
                the efficiency of the code. It helps with code reusability, avoiding function overloading,
                and once written, the can be used for multiple times and cases. Class template eliminates the 
                need to create different algorithms if, in this case, the data type is either a Stress_ball or a 
                Jean or a Purse class, as long as the data types have similar features when being used
                within the generic algorithm.

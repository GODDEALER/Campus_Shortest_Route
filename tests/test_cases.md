# PBLE 2 Test Case

Campus:
1 Main Gate
2 Library
3 Computer Department
4 Laboratory
5 Auditorium

Use roads:
Main Gate-Library = 4
Main Gate-Computer Department = 7
Main Gate-Laboratory = 9
Library-Computer Department = 3
Library-Laboratory = 6
Computer Department-Laboratory = 2
Computer Department-Auditorium = 5
Laboratory-Auditorium = 1
Main Gate-Auditorium = no direct road
Library-Auditorium = no direct road

Source: Main Gate

Expected:
Library = 4, path Main Gate -> Library
Computer Department = 7, path Main Gate -> Computer Department
Laboratory = 9, path Main Gate -> Computer Department -> Laboratory
Auditorium = 10, path Main Gate -> Computer Department -> Laboratory -> Auditorium

# C++: Student Database by using Link List
Student Database using Link List (Structural Node) by the use of functions and procedural approach<br>
<br>
The program has following structures:
##### student:
```
  struct Student {
    int regNo;
    string name;
    int marks[MAX];
};
```

##### node:
```
  struct node {
    Student st;
    node* next;
};
```

This program contains the following functions:<br>
#### readData():
gets the number of students, data of each student and put them in the array.<br/>
#### appendData():
appends data next to the last record.<br/>
#### resultGen():
processes the data and generates the result.<br/>
#### resultShow():
shows the result of all the students in the form of the table.<br/>
#### searchRec():
gets the registration number from the user and search it in the array. if found, then returns the index of it in the array otherwise displays message that record not found.<br/>
#### delRecord():
utilizes the **searchRec()** function and deletes the specific index by overwriting the data to one prior position.<br/>
#### main():
tester for all the things


1) DEPARTMENT table
CREATE TABLE DEPARTMENT (
    ID INT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Location VARCHAR(255)
);

2) EMPLOYEE table
CREATE TABLE EMPLOYEE (
    ID INT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Location INT,
    Manager_ID INT,
    Salary DECIMAL(10, 2),
    FOREIGN KEY (Location) REFERENCES DEPARTMENT(ID),
    FOREIGN KEY (Manager_ID) REFERENCES EMPLOYEE(ID)
);
3) Insert data into DEPARTMENT table
INSERT INTO DEPARTMENT (ID, Name, Location)
VALUES
    (1, 'Engineering', 'Bangalore'),
    (2, 'Sales', 'Delhi'),
    (3, 'Operations', 'Delhi'),
    (4, 'Product', 'Bangalore'),
    (5, 'Production', 'Hyderabad');

   Insert data into EMPLOYEE table
INSERT INTO EMPLOYEE (ID, Name, Location, Manager_ID, Salary)
VALUES
    (1, 'Ram', 1, NULL, 200000),
    (2, 'Vimal', 1, 1, 150000),
    (3, 'Albert', 1, 1, 100000),
    (4, 'John', 2, NULL, 200000),
    (5, 'Taj', 2, 4, 100000),
    (6, 'Deepak', 2, 4, 75000),
    (7, 'Raju', 3, NULL, 100000),
    (8, 'Ramesh', 3, 7, 50000),
    (9, 'Jyoti', 4, NULL, 200000),
    (10, 'Prince', 5, NULL, 200000);
	
4)	SELECT
    d.Name AS Department,
    d.Location,
    COUNT(e.ID) AS EmployeeCount
FROM
    DEPARTMENT d
LEFT JOIN
    EMPLOYEE e ON d.ID = e.Location
GROUP BY
    d.Name, d.Location;

5)
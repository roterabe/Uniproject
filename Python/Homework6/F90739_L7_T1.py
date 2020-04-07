#!/usr/bin/env python 3


class SchoolMember:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display(self):
        print("Name - " + str(name) + " : " + "Age - " + str(age))


class Student(SchoolMember):
    def __init__(self, name, age):
        super().__init__(name, age)
        self.grades = {}
        self.attendance = {}

    def attentCourse(self, sig, year):
        self.sig = sig
        self.year = year
        gradel = []
        self.grades = dict(zip(gradel, year))
        if sig not in self.attendance.keys():
            self.attendance.update(zip(sig, self.grades))

    def addGrade(self, sig, grade):
        self.sig = sig
        self.grade = grade
        gradel = []
        gradel = self.attendance[sig].keys()
        yearl = self.attendance[sig].values()
        gradel1 = gradel
        gradel1.append(grade)
        if self.sig in self.attendance.keys():
            self.attendance[sig] = dict(zip(gradel1, yearl))

    def getCourses(self):
        keys = self.attendance.keys()
        values = self.attendance.values()
        for x in range (len(keys)):
            print(keys[x] + values[x])

    def getAvgGrade(self, sig):
        self.sig = sig
        self.attendance[sig]



class Teacher(SchoolMember):

    def __init__(self, name, age, salary):
        super().__init__(name, age)
        self.salary = salary
        self.courses = {}

    def getSalary(self):
        return self.salary

    def addCourse(self, sig, cname):
        self.sig = sig
        self.cname = cname
        self.courses.update(zip(self.sig, self.cname))

    def getCourses(self):
        keys = []
        keys = self.courses.keys()
        values = []
        values = self.courses.values()
        for x in range (len(keys)):
            print(keys[x] + " " + values[x])
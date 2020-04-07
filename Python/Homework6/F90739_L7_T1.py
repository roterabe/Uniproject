#!/usr/bin/env python 3


class SchoolMember:
    def __init__(self, name, age):
        self.name = name
        self.age = age


class Student(SchoolMember):
    def __init__(self, name, age):
        super().__init__(name, age)
        self.grades = {}
        self.attendance = {}

    def attendCourse(self, sig, year):
        self.sig = sig
        self.year = year
        gradel = []
        self.grades = {"grade": gradel, "year": year}
        if sig not in self.attendance.keys():
            self.attendance[sig] = dict(self.grades)

    def addGrade(self, sig, grade):
        self.sig = sig
        self.grade = grade
        if self.sig in self.attendance.keys():
            self.attendance[sig]["grade"].append(grade)

    def getCourses(self):
        keys = list(self.attendance.keys())
        values = list(self.attendance.values())
        for x in range(len(self.attendance)):
            print(keys[x] + str(values[x]))

    def getAvgGrade(self, sig):
        self.sig = sig
        gradel = []
        sum = 0.0
        if sig in self.attendance:
            gradel = self.attendance[sig]["grade"]
            for x in gradel:
                sum += x
            sum = sum/(len(gradel))
        return round(sum, 2)


class Teacher(SchoolMember):

    def __init__(self, name, age, salary):
        super().__init__(name, age)
        self.salary = salary
        self.courses = {}

    def getSalary(self):
        return self.salary

    def addCourse(self, sig, cname):
        self.sig = str(sig)
        self.cname = str(cname)
        self.courses[self.sig] = self.cname

    def getCourses(self):
        keys = []
        keys = list(self.courses.keys())
        values = []
        values = list(self.courses.values())
        for x in range(len(self.courses)):
            print(keys[x] + " " + values[x])

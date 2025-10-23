🧑‍🏫 **Student Attendance Monitoring System – C Program**

## 🎯 Objective

To develop a dynamic **Attendance Monitoring System** using a **singly linked list** to manage attendance records per class session.

## 🗃️ Data Fields

Each attendance record consists of:
- `Student ID` *(int)*
- `Date` *(string - format: DD-MM-YYYY)*
- `Present/Absent` *(char - 'P' or 'A')*

## ✅ Features

- ➕ Add new attendance record
- ❌ Delete incorrect or duplicate entries
- 🔍 Search by **Student ID** and **Date**
- 📅 Display all attendance records for a given **Date**
- 🔁 Display attendance list in **reverse**
- 📋 Clone entire attendance list for admin review

## 🔧 Data Structure

A **singly linked list** is used where each node represents one attendance entry. Cloning creates a deep copy of the list.

## 🛠️ Operations Summary

| Function | Description |
|---------|-------------|
| `addAttendance()` | Inserts a new attendance record |
| `deleteAttendance()` | Deletes a record based on student ID and date |
| `searchAttendance()` | Searches by student ID and date |
| `displayByDate()` | Shows all attendance for a specific date |
| `displayReverse()` | Displays records in reverse |
| `cloneList()` | Creates a clone of the list for separate admin review |

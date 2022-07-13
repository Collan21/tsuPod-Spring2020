# tsuPod-Spring2020
---
## Description
<p> 
This program creates and stores a list of abstract datatypes, referred to as Songs. Each Song consists of a title, artist, and a size(memory). Collections of songs can be stored in tsuPod objects. 

---
## Features
- Add a song to tsuPod object (only if there is enough memory available)
- Remove a song from the tsuPod 
- Show list of songs
- Shuffle list of songs
- Sort list of songs
- Clear list of songs
---
## Usage
#### Sample Output from test_tsuPod.cpp
```
Testing Successful Song Addition: 
Successful song addition for: ABCs

Testing Successful Song Addition: 
Successful song addition for: Silent Night

Testing Unsuccessful Song Addition: 
Unsuccessful song addition for: Fruit Salad
Maximum memory exceeded.

Testing Successful Traversal and Display: 
Title: ABCs by Michael Jordan, 26 MB
Title: Silent Night by Groot, 16 MB
Title: ZYXs by Jordan Michael, 62 MB
Title: ABCs by Bugs Bunny, 47 MB
Title: Itsy Bitsy by Spider, 27 MB
Title: Twinkle Twinkle by Lil Star, 36 MB
Title: ABCs by Lebron James, 18 MB
Title: Monster Mash by Bobby Pickett, 19 MB

Testing Successful Song Removal: 
Successful song removal for: Silent Night

Updated Song List:
Title: ABCs by Michael Jordan, 26 MB
Title: ZYXs by Jordan Michael, 62 MB
Title: ABCs by Bugs Bunny, 47 MB
Title: Itsy Bitsy by Spider, 27 MB
Title: Twinkle Twinkle by Lil Star, 36 MB
Title: ABCs by Lebron James, 18 MB
Title: Monster Mash by Bobby Pickett, 19 MB

Testing Unsuccessful Song Removal:
Unsuccessful song removal for: Silent Night

Updated Song List:
Title: ABCs by Michael Jordan, 26 MB
Title: ZYXs by Jordan Michael, 62 MB
Title: ABCs by Bugs Bunny, 47 MB
Title: Itsy Bitsy by Spider, 27 MB
Title: Twinkle Twinkle by Lil Star, 36 MB
Title: ABCs by Lebron James, 18 MB
Title: Monster Mash by Bobby Pickett, 19 MB

Testing Successful Song Sort:
Title: ABCs by Bugs Bunny, 47 MB
Title: ABCs by Lebron James, 18 MB
Title: ABCs by Michael Jordan, 26 MB
Title: Itsy Bitsy by Spider, 27 MB
Title: Monster Mash by Bobby Pickett, 19 MB
Title: Twinkle Twinkle by Lil Star, 36 MB
Title: ZYXs by Jordan Michael, 62 MB

Testing Successful Song Shuffle:
Title: ABCs by Michael Jordan, 26 MB
Title: Itsy Bitsy by Spider, 27 MB
Title: ABCs by Bugs Bunny, 47 MB
Title: Monster Mash by Bobby Pickett, 19 MB
Title: ABCs by Lebron James, 18 MB
Title: ZYXs by Jordan Michael, 62 MB
Title: Twinkle Twinkle by Lil Star, 36 MB

Testing memory calculation:
Total Used Memory: 235
Total Remaining Memory: 21

Testing Successful List Deletion:
EMPTY LIST, unable to display
```
---
## Authors
Collan Parker

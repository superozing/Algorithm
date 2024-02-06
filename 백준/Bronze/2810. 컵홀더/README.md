# [Bronze I] 컵홀더 - 2810 

[문제 링크](https://www.acmicpc.net/problem/2810) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 구현, 문자열

### 제출 일자

2024년 2월 7일 04:36:54

### 문제 설명

<p>New theater just opened in Mirko’s home town, and Mirko and Slavko naturally went to check it out. Opening projection was filled to the last place, and Mirko got mad because cup-holders at both sides of his seat were taken and he had nowhere to put his Coke. </p>

<p>A row in theater has N seats. There is a single cup-holder between adjacent seats, and also two additional cup-holders at both ends of the row. Exception to this are pairs of love seats - there is no cup-holder between them. </p>

<p>Your task is to help Mirko. Given sequence of letters describing seats in some row, and assuming that all seats are taken, find the maximum number of people that can put their cups in a cup-holder right next to their seat. </p>

<p>Letter ‘S’ in the sequence denotes ordinary seat, and ‘L’ denotes love seat. Love seats will always come in pairs of adjacent seats. </p>

<p>Diagram below corresponds to sequence ‘SLLLLSSLL’, with asterixes denoting cup-holders. </p>

<p>* S * L L * L L * S * S * L L * </p>

<p>For this example, at least two persons won’t be able to put their cups into cup-holders. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 50), number of seats in a row. </p>

<p>The following line contains a sequence of N letters ‘L’ or ‘S’, describing the row as stated above. </p>

### 출력 

 <p>The first and only line of output should contain the maximum number of people that can put their cups in cup-holder right next to them. </p>


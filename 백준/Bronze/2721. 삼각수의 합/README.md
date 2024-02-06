# [Bronze III] 삼각수의 합 - 2721 

[문제 링크](https://www.acmicpc.net/problem/2721) 

### 성능 요약

메모리: 2020 KB, 시간: 24 ms

### 분류

구현, 수학

### 제출 일자

2024년 2월 7일 04:31:02

### 문제 설명

<p>The nth Triangular number, T(n) = 1 + ... + n, is the sum of the first n integers. It is the number of points in a triangular array with n points on side. For example T(4): </p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/tsum.png" style="height:90px; width:87px"></p>

<p>Write a program to compute the weighted sum of triangular numbers:</p>

<pre>W(n) = SUM[k = 1..n; k*T(k+1)]</pre>

### 입력 

 <p>The first line of input contains a single integer N, (1 ≤ N ≤ 1000) which is the number of datasets that follow. </p>

<p>Each dataset consists of a single line of input containing a single integer n, (1 ≤ n ≤300), which is the number of points on a side of the triangle.</p>

### 출력 

 <p>For each dataset, output on a single line the dataset number, (1 through N), a blank, the value of n for the dataset, a blank, and the weighted sum , W(n), of triangular numbers for n.</p>


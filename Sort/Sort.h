#pragma once
void Sortcompare(void* ptr1(int a[], int n), void* ptr2(int a[], int n), int a[], int n);
void Bubble_sort(int a[], int n);
void Selection_sort(int a[], int n);
void Insert_sort(int a[], int n);
void Shell_sort(int a[], int n);

void Merge_sort_tb(int a[], int n);//自顶向下的归并排序
void Merge_sort(int  a[], int temp[], int min, int max);
void Merge(int a[], int temp[], int min, int mid, int max);


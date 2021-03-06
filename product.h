/*
    Mini Project
    과일을 관리할 수 있는 쇼핑몰 프로그램 제작
    아래 함수 정의 순서대로, 
        CRUD 기능 
        검색 기능
        File 저장 / 불러오기 기능
        구매하려는 과일 저장 기능(찜 기능)
        배송방법에 따라 list-up 기능
        찜여부에 따라 list-up 기능
*/

#include <stdio.h>

typedef struct {
    char pname[50];
    char *des;
    char weight[10];
    int price;
    int choice;
    int reserved;
}Product;

int printMenu(); // 선택지를 출력해주는 함수 
int createProduct(Product *p); // 제품 추가 함수 
int readProduct(Product p); // 하나의 제품 출력 함수 
int updateProduct(Product *p); // 제품 수정 함수 
int deleteProduct(Product *p);  // 제품 삭제 함수
int listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력 
void searchProduct(Product *p[], int count);  // 제품 검색 함수
int saveFile(Product *p, int count); // 파일 저장 함수
int loadFile(Product *p, FILE *fp); // 파일 불러오기 함수
int reserveProduct(Product *p); // 찜하기 기능 함수
void searchByChoice(Product *p[], int count); // 배송방법에 따라 조회하는 함수
void searchByReserved(Product *p[], int count); // 찜하기 여부에 따라 조회하는함수

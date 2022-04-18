#include "manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 메뉴 출력 함수 
int printMenu() {
	int input;
        printf("\n****************************\n");
        printf("1: 제품 등록\n");
        printf("2: 제품 보기\n");
        printf("3: 제품 수정\n");
        printf("4: 제품 삭제\n");
        printf("5: 제품 파일 저장\n");
        printf("6: 제품 파일 불러오기\n");
        printf("7: 제품 찜하기\n");
        printf("8: 찜한 제품 보기\n");
        printf("9: 배송 방법 별 제품 보기\n");
        printf("0: 프로그램 종료\n");
        printf("*****************************\n");

        printf("입력 >>  ");
        scanf("%d", &input);
        return input;
}

// 제품 추가 함수
int createProduct(Product *p) {
        getchar();
        printf("제품의 이름 입력: ");
        fgets(p->pname, 49, stdin);
        p->pname[strlen(p->pname)-1] = '\0';
        printf("설명 입력: ");
        fgets(p->des, 100, stdin);
        p->des[strlen(p->des)-1] = '\0';
        printf("중량 입력: ");
        scanf("%s", p->weight);
        printf("판매 가격 입력: ");
        scanf("%d", &(p->price));
        printf("배송방법(1: 새벽배송/ 2: 택배배송) : ");
        scanf("%d", &(p->choice));
        p->reserved = 0;
        return 1;
}
// 하나의 제품 출력 함수
int readProduct(Product *p) {
        if(p == NULL)
                return 0;
        //printf("---------제품 목록--------\n");
        //printf("제품  설명  중량 가격 배송방법 찜\n");
        printf("%s %s %s %d %d %d\n" , p->pname, p->des, p->weight, p->price, p->choice, p->reserved);
        return 1;
}
// 제품 수정 함수
int updateProduct(Product *p) {
        getchar();
	printf("제품의 이름 입력: ");
        fgets(p->pname, 49, stdin);
        p->pname[strlen(p->pname)-1] = '\0';
        printf("설명 입력: ");
        fgets(p->des, 100, stdin);
        p->des[strlen(p->des)-1] = '\0';
        printf("중량 입력: ");
        scanf("%s", p->weight);
        printf("판매 가격 입력: ");
        scanf("%d", &(p->price));
        printf("배송방법(1: 새벽배송/ 2: 택배배송) : ");
        scanf("%d", &(p->choice));
        return 1;
}
// 제품 삭제 함수 
int deleteProduct(Product **p){
	*p = NULL;
	free(*p);
        return 1;
}

// 전체 등록된 제품 리스트 출력
int listProduct(Product *p[], int count) {
        printf("제품  설명  중량 가격 배송방법 찜\n");
        for(int i=0; i<count; i++){
		if(p[i] == NULL){
			continue;
		}
		printf("%d. ", i+1); 
		readProduct(p[i]);
        }
}

// 제품 검색 함수
void searchProduct(Product *p[], int count) {
}

// 파일 저장 함수 
int saveFile(Product **p, int count) {
	FILE *fp = fopen("product.txt", "wt");

	printf("%d" , count);	
for(int i=0; i<count; i++){
		fputs(p[i]->pname, fp);
		fputs(",", fp);
		fputs(p[i]->des,  fp);
		fputs(",", fp);
		fprintf(fp, "%s, %d, %d, %d,\n" ,p[i]->weight, p[i]->price,p[i]->choice, p[i]->reserved);
	
	}
	fclose(fp);
	return 1;
}
// 파일 불러오기 함수 
int loadFile(Product **p, FILE *fp) {
	int i =0;
	int count =0;
	char line[1024];
	char * ptr;
	

    	while((fgets(line, 1024, fp))!= NULL){
		printf("ii");
		p[i] = (Product*)malloc(sizeof(Product));
		
		//fgets(line, 1024, fp);
		ptr = strtok(line, ","); // 이름
		printf("%s", ptr);
		strcpy(p[i]->pname, ptr);	
		
		ptr = strtok(NULL, ","); // 설명
		printf("%s", ptr);
		strcpy(p[i]->des, ptr);
		
		ptr = strtok(NULL, ","); // 무게 
		printf("%s", ptr);
		strcpy(p[i]->weight, ptr);
		
		ptr = strtok(NULL, ","); // 가격
		printf("%s", ptr);
		p[i]->price = atoi(ptr);
		
		ptr = strtok(NULL, ","); // 배송 방법
		printf("%s", ptr);
		p[i]->choice = atoi(ptr);
		
		ptr = strtok(NULL, ","); // 찜
		printf("%s", ptr);
		p[i]->reserved = atoi(ptr);

        	i++;
        	count++;
    	}
    	return count;
}
// 찜하기 기능 함수 
int reserveProduct(Product *p) {
}
// 배송 방법에 따라 조회하는 함수
void searchByChoice(Product *p[], int count) {
}
// 찜하기 여부에 따라 조회하는 함수 
void searchByReserved(Product *p[], int count) {
}


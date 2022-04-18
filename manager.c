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
        printf("6: 제품 이름으로 검색\n");
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
void searchProduct(Product **p, int count) {
	char findName[50];
	printf("검색할 이름은? ");
	getchar();
	fgets(findName, 50, stdin);
	findName[strlen(findName)-1] = '\0';
	printf("\n*****************************\n");
	for(int i=0; i<count; i++){
		printf("\n%s\n", strstr(p[i]->pname, findName));
		if(strstr(p[i]->pname, findName) == NULL){ 
			continue;
		}
		printf("%2d ", i+1);
		readProduct(p[i]);
	}
}

// 파일 저장 함수 
int saveFile(Product **p, int count) {
	FILE *fp = fopen("product.txt", "wt");

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
		p[i] = (Product*)malloc(sizeof(Product));
		
		//fgets(line, 1024, fp);
		ptr = strtok(line, ","); // 이름
		strcpy(p[i]->pname, ptr);	
		
		ptr = strtok(NULL, ","); // 설명
		strcpy(p[i]->des, ptr);
		
		ptr = strtok(NULL, ","); // 무게 
		strcpy(p[i]->weight, ptr);
		
		ptr = strtok(NULL, ","); // 가격
		p[i]->price = atoi(ptr);
		
		ptr = strtok(NULL, ","); // 배송 방법
		p[i]->choice = atoi(ptr);
		
		ptr = strtok(NULL, ","); // 찜
		p[i]->reserved = atoi(ptr);

        	i++;
        	count++;
    	}
    	return count;
}
// 찜하기 기능 함수 
int reserveProduct(Product **p, int count) {	
	int choice;
	listProduct(p, count);
	printf("찜할 번호를 고르세요 ");
	scanf("%d" , &choice);
	if(choice > count || choice < 0 ){
		printf("없는 번호입니다.\n");
		return 0;
	}
	p[choice-1]->reserved = 1;
	printf("찜 완료 되었습니다.\n");
	return 1;
}
// 배송 방법에 따라 조회하는 함수
void searchByChoice(Product **p, int count) {
	int choice;
	printf("배송방법(1:새벽배송 2:택배배송) ");
	scanf("%d", &choice);
	if(choice == 1){
		for(int i=0; i<count; i++){
			if(p[i]->choice == 2)
				continue;
			printf("%s %s %s %d %d %d\n" , p[i]->pname, p[i]->des, p[i]->weight, p[i]->price, p[i]->choice, p[i]->reserved);
		}					
	}
	else if(choice == 2){
		for(int i=0; i<count; i++){
			if(p[i]->choice == 1)
				continue;
			printf("%s %s %s %d %d %d\n" , p[i]->pname, p[i]->des, p[i]->weight, p[i]->price, p[i]->choice, p[i]->reserved);
		}
	}	
}
// 찜하기 여부에 따라 조회하는 함수 
void searchByReserved(Product *p[], int count) {
	printf("=====찜목록=====\n");
	
	for(int i=0; i<count; i++) {
		if(p[i]->reserved == 0)
			continue;
		readProduct(p[i]);
	}	
}


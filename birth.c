#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 문제점 : atoi 함수는 정수만 받아들이기에 각 배열마다 숫자를 분리시킬 필요가 있음
// 특수문자가 섞이면 안되니 앞 6자리, -, 뒷 7자리를 분리해야함
int main() {
	char Social_number[15];
	char Social_front_year[2]; // 생년만 받아들이는 문자열 생성
	char Social_front_month[2];
	char Social_front_day[2];

	char Social_rear_gender[1];
	scanf("%s", &Social_number);

	Social_front_year[0] = Social_number[0]; 
	Social_front_year[1] = Social_number[1];

	Social_front_month[0] = Social_number[2];
	Social_front_month[1] = Social_number[3];

	Social_front_day[0] = Social_number[4];
	Social_front_day[1] = Social_number[5];

	Social_rear_gender[0] = Social_number[7];


	int birth_year, birth_month, birth_day;
	int gender_code; // 성별, 세기 판별 변수
	birth_year = atoi(Social_front_year); // 생년 문자열을 정수로 변환
	birth_month = atoi(Social_front_month);
	birth_day = atoi(Social_front_day);

	gender_code = atoi(Social_rear_gender);

	if (gender_code == 1 || gender_code == 3) { // 성별이 남성일 경우
		if (gender_code == 1)  // 99년생까지
			printf("당신의 생년월일은 19%d년 %d월 %d일이고 성별은 %s입니다.\n", birth_year, birth_month, birth_day, "남성");

		else if (gender_code == 3) { // 만약 01일경우 0이 생략되고 그냥 1이 되버림(2000년생 이상)
			if (birth_year < 10) { // 01~09일 경우
				printf("당신의 생년월일은 200%d년 %d월 %d일이고 성별은 %s입니다.\n", birth_year, birth_month, birth_day, "남성");
			}
			else {
				printf("당신의 생년월일은 20%d년 %d월 %d일이고 성별은 %s입니다.\n", birth_year, birth_month, birth_day, "남성");
			}
		}

	}

	else if (gender_code == 2 || gender_code == 4) {
		if(gender_code == 2) 
			printf("당신의 생년월일은 19%d년 %d월 %d일이고 성별은 %s입니다.\n", birth_year, birth_month, birth_day, "여성");
		else if (gender_code == 4) {
			if (birth_year < 10) {
				printf("당신의 생년월일은 200%d년 %d월 %d일이고 성별은 %s입니다.\n", birth_year, birth_month, birth_day, "여성");
			}
			else {
				printf("당신의 생년월일은 20%d년 %d월 %d일이고 성별은 %s입니다.\n", birth_year, birth_month, birth_day, "여성");
			}

		}

	}

	return 0;
}
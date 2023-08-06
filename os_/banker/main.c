/*
* Midterm_Report.c
*
* Created: 2022-05-17 오후 6:13:44
* Author : 장상훈(학번:1820662)
*/
// #include <avr/io.h>
#define F_CPU 16000000UL
// #include <util/delay.h>
unsigned char array1[4]={0x3F, 0x7D, 0x7D, 0x5B};
unsigned char array2[4]={0x01, 0x02, 0x04, 0x08};
int main(void)
{
// DDRA=0xff;//포트 A를 출력으로 설정
// PORTA=0b00111110;//임의의 수 62에 맞게 LED에 2진수로 표시
// DDRC=0xff;//포트 C의 방향설정
// DDRG=0x0f;//포트 G의 방향설정
//  while (1)
//  {
for(int i=0;i<4;i++)
{
    printf("%c\t, 학번",array1[i]);
    printf("%d\t, 자리",array2[i]);
//가장 오른쪽 FND부터 0 6 6 2를 차례대로 표시
// PORTC=array1[i];//array1에 학번 뒷 4자리수를 뽑아와서 출력
// PORTG=array2[i];//array2에 뽑아온 수를 넣을 FND 위치 지정
// _delay_ms(2);//2ms만큼 지연해서 연속된 것처럼 보이게 함
// }
}
}

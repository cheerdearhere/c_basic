���(Control statement)
- ���α׷��� �� ������ �ٽ� �ٰŰ� �� ������ �߿��� ����
- ASCII code(����� �� �ִ� ����)�� ����� ����
	- �� : ��� , ����(�޸�), ������
	- ��(��): ���� ����
	- ����; : ���� ����
	- �Լ�\{ } : ������ ����
- ��� ���α׷��� ���������̰� �⺻������ ������ �Ʒ��� �帧�� ���󰣴�
	- ��ü���⵵ ��ü�� �߽��ϴ� ������ ���������� ���� ������ �ǹ����� �ʴ´�
	- ������ ���� �������� ���� �������̰� ������ compile������ �̷�����.
	- ����� �Է��� �޴� ��Ÿ�� ��Ȳ������ ����� ���� ������ �Է¿� ���� �帧�� �����ؾ��Ѵ�
	- �� �帧�� �����ϴ� ���� ���

# I. if
- �б⹮(Branching statement)
- ���ǽ��� true(1)�϶��� �ڵ������ ����
- ���׿����ڿ� ���������� �����ϳ� ���׿����ڴ� �� ������ �����̶�� if���� ���� ������ ó���Ѵ�. 
## A. if
- if�� �ǽ��� ���ǻ���
	- ���ǽ� ��ȣ �ڿ� ;�� �ٿ� ������ �����ʱ�
	- ���౸���� �������ΰ�� �� \{}�� ���� ������ �鿩���⸦ ��ġ��Ű��
```c
if(���ǽ�) ~~~;
//���ǽİ� ������ ������ �ᵵ ��
if(���ǽ�) 
	~~~;
// �ڵ������ ���� ������ ��� {}�� �������� �����Ѵ�
if(���ǽ�){
	// ���� ����
}
```

```dockerfile
����1 
����ڷκ��� �Է� ���� ���� �� ���� ū ���� ����ϴ� ���α׷��� �ۼ�. 
���ѻ���
	������ ��ȣ�� �ִ� 32��Ʈ ������ ����
	scanf_s�Լ��� �ѹ��� �� ���� �Է�
	���������� �ִ��� ��� �����ϴ� ������ �ۼ�
	if�� ���
��� ����
	10
	20
	30
	MAX : 30
```
[�ǽ��ڵ�](../c_basic/ch11ControlStatement/control_01Question.c)
3�׿����ڰ� �� ������� if���� ���� �������� �б⸦ ó���Ѵٴ� ���̰� ����
```dockerfile
����2 ����ڷκ��� ���̸� �Է¹޾� ��������� ����ϴ� ���α׷�
���ѻ���
	������ ��ȣ�� �ִ� 32��Ʈ ������ ����
	���� �⺻����� 1000������ ����
	20�� �̸��� ��� 25% ����
	20�� �̻��� ������ ���� ����
	���̰� 20�� �̻��� ��� 20���θ� ���
	if�� ���
��� ����
	15
	����: 15, �������: 750��
	25
	����: 20, �������: 1000�� 
```
[�ǽ��ڵ�](../c_basic/ch11ControlStatement/control_02Question.c)
## B. if else
- ���ǽ��� �����ϴ� ���� �������� �ʴ� ��� ����Ǵ� ���� ��Ÿ������ ��� �� �� �ִ� ���
- else�� ;�� ������� �ʰ� �������� ��� \{}�� ������ ����
```c 
	if (nInput <= 10)
		nSelect = 10;
	else
		nSelect = 20;
	// 3�� �����ڷε� ����
	nSelect = nInput <= 10 ? 10 : 20;
```
- ����� �Է¿� �־ ������ ó���� �� ����
	- if ���� �Ʒ����� 10 �ʰ��� nInput�� ������ �ʿ䰡 ��������
	- � ������ �ٰŷ� 2���� ��
	- �ڷᱸ���� binary tree
## C. if else ��ø
- ���� ��� ���ο� �ٽ� ����� �־ ����� �� ����
- ���� ��󰡴��� ���� ���� ������ �� �Ƕ�̵� ������ �з�
- ���ǿ� ���� �з��� ����
```
if(nInput >= 80){//��з�
	if(nInput >= 90)
		ch = 'A';
	else
		ch = 'B';
}
else{
	if(nInput >= 70)
		ch = 'C';
	else{
		if(nInput < 60)
		ch = 'F';
	}
}
```

```dockerfile
����3: ���� �⺻����� 1000������ �����ϰ� ���̿� ���� ������ ���� �������� ����.
����
	0~3		������		100%(����)
	4~13	���		50%
	14~19	û�ҳ�		25%
	20~		����			0%
��� ����
	����: 20
	���: 1000
������ tip: �켱 2������ �����ϰ� �� ���ҷ� ������
```
[�ǽ��ڵ�](../c_basic/ch11ControlStatement/control_03Question.c)
- ������ Ư���Ǿ������� ���� 2���ҷ� 2��Ʈ���� ������ �� �ִ�
## D. ���� if
- if else�� ���� ���̾� ����� �Ͱ� ���� ����
- ���� ���ǽ��� ����� ������ ���� �ٿ���
- ���ȵǴ� ������ �� ���ĵǾ��ִ� ���¿��� ����
- short circuit�� ������ ���� �Ǻ�
```c
if(nInput >= 90){
	...
}
else if(nInput >= 80) {
	...
}
else if(nInput >= 70){
	...
}

	...���� ����...

else {
	...
}
```
- ���� ���� �� �ϳ��� ��� : if-else if
- ���� ���� �� �ش�Ǵ� ����� ��� : if ���� ��

# II. ������ ��ø�� �ĺ��� �˻� ����
- ������ ���� ���� ������ �ش� ������ ����� �������� ���ѵ�(��������)
- ������� ���� ����� ��� ������ �������� �� �ڵ����� 
- �ڵ� ������ ����� �������� �Ѿ�� �ڵ����� �Ҹ�
- �ĺ���(������ name)�� ���� ��� �ֱ� �������� �켱
	- ���� �ֱٿ� �����
	- ���� stack frame�� ����
	- �˻� ������ stack memory�� LIFO�� ���� �˻��Ѵ�
```c
//������ ���� ������ ���������� �������� ���� �ߺ����� ���� ����
int main(void){
	int x=1;//1
	printf("%d\n",x); //1 stack frame
	if(x>0){
		int x = 2;//2
		printf("%d\n",x); //2 stack frame
		if(x > 1 ){
			int x = 3;//3 
			printf("%d\n",x); //3 stack frame
		}
	}
//	printf("%d",b); // b�� ���� �Ұ�
	printf("%d\n",x);//2,3�� scope�� ��� stack frame�� ����� �Բ� �Ҹ�� 
	// 1 stack frame ȣ��
}
```
- ����
	- ��������: ���� ������ �������� ����� �� �ִ� ����
	- �ڵ�����: stack memory�� ȣ���ϴ� ������ �ش� stack frame�� ����� �ڵ����� �������

# III. switch - case
- if-else if�� ������ ���
	- ���ǽ��� �񱳿����� �ƴ� ���ĸ� ���(==)
- ������ �з��ϰ� ��츦 �����ϴ� ���
- �� case�� ����� ��ġ�ϴ� ���� �ش��ϴ� ����
	- �Ǽ��� �ȵ��� ��� 
- case�� �ݷ����� ����
- �� case�� ���� break�� ����(�����ϸ� �Ʒ� case�� ���������� ����)
- elseó�� �׿� ó���� default
```c
char charOperator = 0;
switch(charOperator){
	case '+' : 
		...
		break;
	case '-' : 
		...
		break;
	case '*' : 
		...
		break;
	case '/' : 
		...
		break;
	default:
}
```
- break�� ������ �Ʒ� case���� ����
```c
	case '*' : 
		���� A
//		break;
	case '/' : 
		���� B
		break;
		=> ���� A > ���� B > switch break
```
# IV. goto
- ������ goto
- ���������� �ظ��ϸ� �Ⱦ��� ���
- ���α׷��� �帧�� ���� ���� ��� �����ϴ� ���
- ���α׷��� �帲�� ��ų �� �־� ��κ� ����� ������ ����
	- �ʿ信 ���� ���� �� �ְ����� �ظ��ϸ� �Ⱦ�
	- ��� ������ �ʿ��Ҷ��� ���⵵ ��.
- ����
	- ���� ����(������ ����)
	- �ʿ� ���ǿ� ���� goto �󺧸�;���� ����

```c
	int nInput;
INPUT:
	printf("Input Number : ");;
	scanf_s("%d", &nInput);

	if (nInput < 0 || nInput > 10)
		goto INPUT;
		// ���ǿ� ���� �ʴ� ��� ���Է� ��û
	
	puts("END");
}
```
- ������ �帧���� �����ϴ� ù �ڵ�
- Ƚ���� üũ�ϸ� �ݺ��� �����ؼ� ó���� �� ���� 
- ���Ǿ��� goto�� ���ϱ�
	- stream�̳� OS �ڿ� ���� ����Ҷ� close/clear/clean ó���� ���� ����ϱ⵵ ��
	- exception handling, validation ����� ����ϱ⵵...
# V. boolean ����ϱ�
- C���� boolean�� ����
- �̸� ���� �ʹٸ� stdbool ���
```c
#include <stdbool.h>
```

[��� ��ü �ڵ�](../c_basic/ch11ControlStatement)
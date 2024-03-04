
- ���� �ڷ����� ��� ���ο� �ϳ��� �������� ���(����)
	- ex: array, struct, union
	- ������
		
	|����|�迭|����ü|����ü|
	|---|---|---|--|
	|����|index|member|member|
	|����|���� Ÿ��|���� Ÿ��|���� Ÿ��|
	|����|����|����|����|
	
- ������ �����ϴ� �ΰ��� ��Ŀ� �˸��� �ΰ��� ��� 
	- NoSQL > Array
		- ����
	- RDBMS > Struct
		- record�� column 
		- Map
- ����ü�� �������� ������ ���س��� �� ���θ� ���������� ���(�Ʒ����� �ٽ�)

# I. ����ü
- ����ü�� �ִ� ��ҿ� �̸��� �ּ� ����: member
- ����ü ������ ���� ���� ��ҿ� ������ ���� ������� �����ڸ� ���
	-  . : �������� �ش� ����ü�� ����� ��
	- -> : ���� �Ҵ綧�� ->�� ���
- ����ü ����(or �ν��Ͻ�) ����� �ʱ갪�� ����� ���� �ݵ�� ��� ���� ������ �������
- typedef ������ �����ϴ� ���� �Ϲ���
- java, C++�� class �ý���
## A. ����
- ����� Ű����: struct
```c
struct USERDATA
{
	int nAge; // member
	char szName[32];
	char szPhone[32];
}
```
- ȣ�� ��: struct ����ü�̸� ����ü������ = {���,���,���...};
```c
int main(void)
{ //|-- ���� Ÿ�� --|������| = {members...}
	struct USERDATA user	= {0,"",""}
}
```
- struct Ű���� �����ϱ�: ȣ�� �ο��� struct �����ϱ�
	- ����ü ����� �յڿ� typedef�� ����ü �������� ������ 
```c
typedef struct USERDATA{
	int nAge;
	char szName[32];
	char szPhone[32];
}USERDATA
```
- ȣ��ο��� struct Ű���� ���� ��� ����
```c
int main(void)
{ //|���� Ÿ��|������| = {members...}
	USERDATA	user  = {0,"",""}
}
```
## B. �ν��Ͻ��� ��� �����ϱ�
- ����ü�� �ν��Ͻ� ����
```c
USERDATA	user  = {0,"",""}
//struct USERDATA user = {0,"",""};
```
- �ش� �ν��Ͻ��� ����� ����: ������� ������
```c
	user.nAge = 10;
```
- ���ڿ��� ���� ����
```c
strcpy_s(user.szName, sizeof(user.szName), "Hoon");
strcpy_s(user.szPhone, sizeof(user.szPhone), "010-1234-1234");
```
- ���
```c
printf("user: \n�̸�: %s, ����: %d, ����ó: %s\n",user.szName, user.nAge, user.szPhone);
```
# II. ����ü�� �޸� ���� �Ҵ�
## A. ����ü ���� 
- �ڷᱸ���� �غ�(����) > ���� 
- ����ü�� �迭 ���� ����
- malloc()���� �������� ������ �����ϴ� ��쵵 �Ϲ���
- ����ü�� ���� ������ ���� ����� ��� ���� �����ڰ� �޶���
- �Լ� ��ȯ���̳� �Ű����� ��� ����
	- �� �κ��� �����͸� �����ϴ� ���� �� ���� ���� ���� 
## B. ���� �Ҵ� ����
- ����ü�� ������ ���� ���� �Ҵ�
	- malloc()��  void*�� ��ȯ�ϹǷ� ���� ����ȯ ������ ���ִ� ���� �Ϲ��� 
	- sizeof(USERDATA)�� �Է°����� ����� ����
		- structure member alignment(����ü ��� ����)�� ���������
```c
	USERDATA* pUser = NULL;
	//����ü�� ������ ���� ���� �Ҵ�
	pUser = (USERDATA*)malloc(sizeof(USERDATA));
	
	pUser->nAge = 10;
	strcpy_s(pUser->szName, sizeof(pUser->szName), "hgeee");
	strcpy_s(pUser->szPhone, sizeof(pUser->szPhone), "010-1111-1222");

	printf("user: \n�̸�: %s, ����: %d, ����ó: %s\n", 
		pUser->szName, pUser->nAge, pUser->szPhone);
	//�Ҵ� ����
	free(pUser);
```
## C. ����ü�� �Լ�
### 1. ����ü�� ��ȯ�ϱ�?
- ���� ���� ���� ��ȯ�� �� �ִ�.
	- ���⼭�� �޸� �ּҸ� ��ȯ�ϴ� ���� �ƴ��� ����
```c
USERDATA GetUserDAta(void) {
	USERDATA user = { 0 };
	scanf_s("%d%*c", &user.nAge);
	gets_s(user.szName, sizeof(user.szName));
	gets_s(user.szPhone, sizeof(user.szPhone));

	return user;
}
```
- ������ �׺��� ����ü�� �����͸� �޾Ƽ� ���� ó���ϴ� ���� �� ����
	- ���� ������ ����
```c
void GetUserData(USERDATA *pUser) {
	USERDATA user = { 0 };
	puts("ȸ�������� �Է��մϴ�.\n����: ");
	scanf_s("%d%*c", &user.nAge);
	puts("\n�̸�: ");
	gets_s(pUser->szName, sizeof(pUser->szName));
	puts("\n����ó: ");
	gets_s(pUser->szPhone, sizeof(pUser->szPhone));

	return;
}

int main(int argc, char* argv[]) {
	StartChapter(); 

	USERDATA user = { 0 };
	
	GetUserData(&user);

	printf("user: \n�̸�: %s, ����: %d, ����ó: %s\n", 
		user.szName, user.szName, user.szPhone);

	CloseChapter();
	return 0;
}
```
### 2. ����ü�� �Ű������� ����ϱ�
- �����ϻ� �̷��� ���� ���� ����
```c
USERDATA GetUserData(USERDATA userParam) {

	printf("user: \n�̸�: %s, ����: %d, ����ó: %s\n",
		userParam.szName, 
		userParam.nAge, 
		userParam.szPhone);
	USERDATA user = { 
		10, "Hoon", "010-1111-2222"
	};
	return user;
}

int main(int argc, char* argv[]) {

	USERDATA user = {
		20, "Joon", "010-3333-4444"
	};
	USERDATA result;

	result = GetUserData(user);

	printf("result: \n�̸�: %s, ����: %d, ����ó: %s\n", 
		result.szName, result.nAge, result.szPhone);
```
>console)
```
user:
�̸�: Joon, ����: 20, ����ó: 010-3333-4444
result:
�̸�: Hoon, ����: 10, ����ó: 010-1111-2222
```
>disassemble
- ȣ���
```

	USERDATA user = {
00007FF7C84D1B72  mov         dword ptr [user],14h  
00007FF7C84D1B79  lea         rax,[rbp+14h]  
00007FF7C84D1B7D  lea         rcx,[string "Joon" (07FF7C84DAC10h)]  
00007FF7C84D1B84  mov         rdi,rax  
00007FF7C84D1B87  mov         rsi,rcx  
00007FF7C84D1B8A  mov         ecx,5  
00007FF7C84D1B8F  rep movs    byte ptr [rdi],byte ptr [rsi]  
00007FF7C84D1B91  lea         rax,[rbp+19h]  
00007FF7C84D1B95  mov         rdi,rax  
00007FF7C84D1B98  xor         eax,eax  
00007FF7C84D1B9A  mov         ecx,1Bh  
00007FF7C84D1B9F  rep stos    byte ptr [rdi]  
00007FF7C84D1BA1  lea         rax,[rbp+34h]  
00007FF7C84D1BA5  lea         rcx,[string "010-3333-4444" (07FF7C84DAC18h)]  
00007FF7C84D1BAC  mov         rdi,rax  
00007FF7C84D1BAF  mov         rsi,rcx  
00007FF7C84D1BB2  mov         ecx,0Eh  
00007FF7C84D1BB7  rep movs    byte ptr [rdi],byte ptr [rsi]  
00007FF7C84D1BB9  lea         rax,[rbp+42h]  
00007FF7C84D1BBD  mov         rdi,rax  
00007FF7C84D1BC0  xor         eax,eax  
00007FF7C84D1BC2  mov         ecx,12h  
00007FF7C84D1BC7  rep stos    byte ptr [rdi]  
		20, "Joon", "010-3333-4444"
	};
	USERDATA result;

	result = GetUserData(user);
00007FF7C84D1BC9  lea         rax,[rbp+210h]  
00007FF7C84D1BD0  lea         rcx,[user]  
00007FF7C84D1BD4  mov         rdi,rax  
00007FF7C84D1BD7  mov         rsi,rcx  
00007FF7C84D1BDA  mov         ecx,44h  
00007FF7C84D1BDF  rep movs    byte ptr [rdi],byte ptr [rsi]  
00007FF7C84D1BE1  lea         rdx,[rbp+210h]  
00007FF7C84D1BE8  lea         rcx,[rbp+1A8h]  
00007FF7C84D1BEF  call        GetUserData (07FF7C84D11DBh)  
```
- �Լ� ����
```
	printf("user: \n�̸�: %s, ����: %d, ����ó: %s\n",
00007FF7C84D1A4E  mov         rax,qword ptr [&userParam]  
00007FF7C84D1A55  add         rax,24h  
00007FF7C84D1A59  mov         rcx,qword ptr [&userParam]  
00007FF7C84D1A60  add         rcx,4  
00007FF7C84D1A64  mov         r9,rax  
00007FF7C84D1A67  mov         rax,qword ptr [&userParam]  
00007FF7C84D1A6E  mov         r8d,dword ptr [rax]  
00007FF7C84D1A71  mov         rdx,rcx  
00007FF7C84D1A74  lea         rcx,[string "user: \n\xc0\xcc\xb8\xa7: %s, \xb3\xaa\xc0\xcc: %d, \xbf\xac\xb6\xf4@"... (07FF7C84DADB8h)]  
00007FF7C84D1A7B  call        printf (07FF7C84D119Ah)  
		userParam.szName, 
		userParam.nAge, 
		userParam.szPhone);
	USERDATA user = { 
00007FF7C84D1A80  mov         rax,qword ptr [user]  
00007FF7C84D1A87  mov         dword ptr [rax],0Ah  
00007FF7C84D1A8D  mov         rax,qword ptr [user]  
00007FF7C84D1A94  lea         rcx,[string "Hoon" (07FF7C84DADE8h)]  
00007FF7C84D1A9B  lea         rdi,[rax+4]  
00007FF7C84D1A9F  mov         rsi,rcx  
00007FF7C84D1AA2  mov         ecx,5  
00007FF7C84D1AA7  rep movs    byte ptr [rdi],byte ptr [rsi]  
00007FF7C84D1AA9  mov         rax,qword ptr [user]  
00007FF7C84D1AB0  add         rax,9  
00007FF7C84D1AB4  mov         rdi,rax  
00007FF7C84D1AB7  xor         eax,eax  
00007FF7C84D1AB9  mov         ecx,1Bh  
00007FF7C84D1ABE  rep stos    byte ptr [rdi]  
00007FF7C84D1AC0  mov         rax,qword ptr [user]  
00007FF7C84D1AC7  lea         rcx,[string "010-1111-2222" (07FF7C84DADF0h)]  
00007FF7C84D1ACE  lea         rdi,[rax+24h]  
00007FF7C84D1AD2  mov         rsi,rcx  
00007FF7C84D1AD5  mov         ecx,0Eh  
00007FF7C84D1ADA  rep movs    byte ptr [rdi],byte ptr [rsi]  
00007FF7C84D1ADC  mov         rax,qword ptr [user]  
00007FF7C84D1AE3  add         rax,32h  
00007FF7C84D1AE7  mov         rdi,rax  
00007FF7C84D1AEA  xor         eax,eax  
00007FF7C84D1AEC  mov         ecx,12h  
00007FF7C84D1AF1  rep stos    byte ptr [rdi]  
		10, "Hoon", "010-1111-2222"
	};
	return user;
00007FF7C84D1AF3  mov         rax,qword ptr [user]  
}
```
- �ٽ� ȣ���
```
00007FF7C84D1BF4  lea         rcx,[result]  
00007FF7C84D1BFB  mov         rdi,rcx  
00007FF7C84D1BFE  mov         rsi,rax  
00007FF7C84D1C01  mov         ecx,44h  
00007FF7C84D1C06  rep movs    byte ptr [rdi],byte ptr [rsi]  

	printf("result: \n�̸�: %s, ����: %d, ����ó: %s\n", 
00007FF7C84D1C08  lea         r9,[rbp+0A4h]  
00007FF7C84D1C0F  mov         r8d,dword ptr [result]  
00007FF7C84D1C16  lea         rdx,[rbp+84h]  
00007FF7C84D1C1D  lea         rcx,[string "result: \n\xc0\xcc\xb8\xa7: %s, \xb3\xaa\xc0\xcc: %d, \xbf\xac@"... (07FF7C84DAFC0h)]  
00007FF7C84D1C24  call        printf (07FF7C84D119Ah)  
		result.szName, result.nAge, result.szPhone);

	CloseChapter();
00007FF7C84D1C29  call        CloseChapter (07FF7C84D107Dh)  
	return 0;
00007FF7C84D1C2E  xor         eax,eax  
}
```
- �Ը� ū ����ü�� �ѱ涧 �� ��ü�� �ѱ�� ���縦 ���� �޸� �Һ� �ſ� Ŀ����.
- �� ���� �����ͷ� ó���ϸ� �޸� �ּ� �̵������� ó���� �� �־� ȿ���� ������ �ִ�. 
```c
void GetUserData(USERDATA *userParam) {
	USERDATA user = { 
		10, "Hoon", "010-1111-2222"
	};
	//memcpy(userParam, &user, sizeof(user));
	*userParam = user;
	//��������δ� ����
	//����ü�� ���� ��� �񱳰� �ƴ� �ܼ� ������ ����(������ �޸� ī��)
	return;
}

int main(int argc, char* argv[]) {
	StartChapter(); 

	USERDATA user = {
		20, "Joon", "010-3333-4444"
	};

	USERDATA result;
	GetUserData(&result);

	printf("result: \n�̸�: %s, ����: %d, ����ó: %s\n", 
		result.szName, result.nAge, result.szPhone);

	CloseChapter();
	return 0;
}
```
- ��ȯ���� ������ ��� �����Ҵ��� ���.
	- ���� ��ȯ ������ ���� ��� �ʼ� 

## D. ����ü�� ����� ���� ����ü
- ����ü ������ �ٸ� ����ü�� ����� �� �� ����
- 2�������� �������� ����
- �����Ϸ����� ������ �˷��� �ϹǷ� ��� ������ �߿�
- �ڱ� �ڽſ� ���� �����͸� ����� ���� ����ü�� ����
	- �ڱ� ���� ����ü
	- ���� ����Ʈ(�����͸� ���� ����...)
### 1. ����
- �� ���� ������ ���� ���
```c
typedef struct MYBODY {
	int nHeight;
	int nWeight;
} MYBODY;

typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];
	MYBODY bodySize;//���⼭ ���
} USERDATA;
```
### 2. �ʱ�ȭ 
- ������ ���Ϸ� �����ؼ� �ҷ���
- ���� ����� ���� x
```c
	USERDATA user = {
		18,
		"Hone",
		"010-1234-1234",
		{176, 70}
	};
```
### 3. ��� ����
```c
	printf("�̸�: %s, ����: %d, ����ó: %s\n h-w: %d - %d",
		user.szName,
		user.nAge,
		user.szPhone,
		user.bodySize.nHeight,
		user.bodySize.nWeight
	);
```
### 4. �ڱ����� ����ü
- ����ÿ��� ���� typedef�� ������ ���� �����Ƿ� 'struct ����ü��*'�� ���
```c
typedef struct USERDATA {
	int nAge;
	char szName[32];
	char szPhone[32];

	struct USERDATA* pFront;// pointer
	struct USERDATA* pNext;// pointer 
} USERDATA;
```
- �ʱ�ȭ�� ��带 ����ϴ� �����ʹ� �ϴ� NULL
```c
	USERDATA user1 = {
		18,
		"Hone",
		"010-1111-1234",
		NULL
	};
	USERDATA user2 = {
		25,
		"Jone",
		"010-2222-1234",
		NULL
	};
	USERDATA user3 = {
		13,
		"Cone",
		"010-3333-1234",
		NULL
	};
```
- ��忡 ������ �ο��ϴ� �۾�
	- ���� �߿�
	- �Ϲ������δ� ���������� ���� �������� ����
	- malloc�� ����� ���� �Ҵ��ؼ� ���
	- ���� ������ Linked list�� �����ϻ�
	- ���� �հ� �ڴ� �����Ƿ� NULL �Ǵ� �����ڰ� ������ script
```c
	user1.pNext = &user2;
	user2.pFront = &user1;
	user2.pNext = &user3;
	user3.pFront = &user2;
```
- ��ȯ���̶�� ó���� ������ ��忡 ����
```c
	user1.pFront = &user3;
	...
	user3.pNext = &user1;
```
- ����Ʈ�� ���޾� ����ϴ� ���� ����ؾ��ұ�... 
```c
void GetUserList(USERDATA* user) {	
	printf("�̸�: %s, ����: %d, ����ó: %s\n",
		user->szName,
		user->nAge,
		user->szPhone
	);
	if (user->pNext != NULL)
		GetUserList(user->pNext);
}
```

### 5. �ǽ�����
```dockerfile
������ ���Ḯ��Ʈ ����(struct_simpleLinkedList.c)�� Ȱ���� ���Ḯ��Ʈ ��ü�� ������ ����ϴ� �Լ� �ۼ�
���ѻ���
	�Լ��� �Ű������δ� ����� ����� �ּҸ� ����
	���ȣ���� ���� ���� ���� �̵��ϵ��� ����
����ü
	typedef struct USERDATA {
		char szName[32];
		char szPhone[32];

		struct USERDATA* pFront;
		struct USERDATA* pNext;
	} USERDATA;
main
	USERDATA userList[4] = {
		{"��ν�","1234",NULL},
		{"�̹���","2345",NULL},
		{"�����","3456",NULL},
		{"�����","4567",NULL},
	};
	userList[0].pNext = &userList[1];
	userList[1].pNext = &userList[2];
	userList[2].pNext = &userList[3];
	userList[3].pNext = NULL;
Ȯ�ο� �ڵ�(�ǽ������� ����)
	USERDATA* pUser;
	pUser = &userList[0];
	while (pUser != NULL) {
		printf("�̸�: %s, ����ó: %s\n",
			pUser->szName,
			pUser->szPhone
		);
		pUser = pUser->pNext;
	} 
```
[�ǽ� �ڵ�](../c_basic/ch16Struct/struct_01Question.c)

- �ݺ����� ���� ������


## E. ����ü ��� ����(����ü ���� �߿��� �κ�)
- ����ü�� �̷�� ����� �޸� ������ ���� ���Ǹ� ���� ������ �������� �ʰ� ���� ������ �޸𸮸� ����
- ������ ������ų ��� ��ó���⸦ �̿��� ���� ����
> #pragma pack()

- ����ü ũ�� �����ϱ�
```c
typedef struct USERDATA {
	char ch; 
	int nAge;
	char szName[5];
} USERDATA;
```

- ����: 10
	- char: 1byte
	- int: 4byte
	- char[5]: 5byte

```c
int main(int argc, char* argv[]) {
	USERDATA user = { 'A',10,"Choon" };
	
	int data = 0x11223344;// ���� ������ ������ ���� ���� ������
	
	printf("%d\n", sizeof(USERDATA));

	return 0;
}
```
> console) 16

- �̷� ����

<table>
	<thead>
		<tr>
			<th colspan="4">���� �޸�</th>
		</tr>
	</thead>
	<tbody style="text-align:center">
		<tr>
			<td style="background:azure;color:#000;font-weight: bolder;">ch</td>
			<td style="color:#fff;background:#000">x</td>
			<td style="color:#fff;background:#000">x</td>
			<td style="color:#fff;background:#000">x</td>
		</tr>
		<tr>
			<td colspan="4" style="background:azure;color:#000;font-weight: bolder;">nAge</td>
		</tr>
		<tr>
			<td colspan="4" style="background:azure;color:#000;font-weight: bolder;">szName[0~3]</td>
		</tr>
		<tr>
			<td style="background:azure;color:#000;font-weight: bolder;">[4]</td>
			<td style="color:#fff;background:#000">x</td>
			<td style="color:#fff;background:#000">x</td>
			<td style="color:#fff;background:#000">x</td>
		</tr>
	</tbody>
</table>

![memory](img/struct_memory.png)

- �����ϴ� ��� 2����
	- ������Ʈ �����ϱ� 
		- c/c++ > code generation > ����ü ���� ����(���ϴ� ��Ʈ ���� ���� ����)	
		- ����ü ��� ������ �����ϸ� ���� ���� 
		- but ���� ����ƴ�
			- ���뼳���� �ǵ�°� ����
			- ��� ������Ʈ�� ����ü�� ������ �޾� ������ �߻��� ���ɼ��� �ſ� ����
	- ������Ʈ ��ܿ� ����
		- ������ �ݵ�� �����ؾ߸��ϴ� ��쿡 ���... 

```c

//push: �����Ϸ��� �����Ѽ� �� ����ü�� 1byte ������ �����϶�� �ǹ�
#pragma pack(push,1)
typedef struct USERDATA {
	char ch;
	int nAge;
	char szName[5];
} USERDATA;
```

![pragma pack](img/struct_pragma_pack.png)

# III. ��Ʈ�ʵ�
- 1byte(8bit) ������ ���� �߶� ���� ���� ����
	- 8bit: ���� ����ġ 8��(on/off)
- �Ӻ���� �ý����� �����Ҷ� ���(���� ��ȣ�� �ٷ궧 ���)
	- �׳� �̷��� �ִ� ������
- ��Ʈ mask > shift ����� ��ü
- ����� ��Ʈ ���� ������
	- unsigned char (top, right, left, main)
	- ���� ������ main
- ��� ����� ���� ����� ����� 8bits �� ������ ���� ����

```c
typedef struct _DATAFLAG {
	unsigned char main : 1;//bit �ڸ� �� 0~1
	unsigned char left : 2;//0~3
	unsigned char right : 3;//0~7
	unsigned char top : 2;//0~3
} DATAFLAG;
```

| top |   | right |   |   | left |   | main |
|---|---|-------|---|---|------|---|------|
| 0 | 0 | 0     | 0 | 0 | 0    | 0 | 0    |


```c
	DATAFLAG flagSwitch = { 1,3,7,5 };
	
	printf("data: \n\tmain: %d\n\tleft: %d\n\tright: %d\n\ttop: %d\nflag: %X\nsize: %zd\n",
		flagSwitch.main,
		flagSwitch.left,
		flagSwitch.right,
		flagSwitch.top,
		*((unsigned char*)&flagSwitch),
		sizeof(flagSwitch)
	);
```
- top�� 0~3�ε�  4�� �Էµ� ��Ȳ(Over)

| t | t |r|r|r|l|l |m|
|---|---|--|--|--|--|--|--|
| ? | ? |1|1|1|1|1|0|

>console)
```
data:
        main: 0
        left: 3
        right: 7
        top: 0
flag: 3E
size: 1
```
- ��� �ؼ�
	- m,l,r�� �ʱ�ȭ �Ѵ��
		- top: 4�� 0�̵�
	
			||t|t|r|r|r|l|l |m|
			|--|--|--|--|--|--|--|--|--|
			|<s style="color:red">1</s>|0|0|1|1|1|1|1|0| 
	
		- top�� 5�� ������ 1�� ��
			- overflow �߻�: ������ �Ѿ 1�� ��������� �� ���� ������ ���� �״�� �ԷµǾ�
				
			||t|t|r|r|r|l|l |m|
			|--|--|--|--|--|--|--|--|--|
			|<s>1</s>|0|<span style="color:red">1</span>|1|1|1|1|1|0| 
 
			- top�� 100�� 1�����ŵ� 00�̵ǰ�, 101�� 01�� ���´�	
	- 16������ �б�: 0+0+2+1 + 8+4+2+1

		|bit|t|t|r|r|r|l|l |m|
		|--|--|--|--|--|--|--|--|--|
		|flag|0|0|1|1|1|1|1|0| 
		|�ڸ�|8|4|2|1|8|4|2|1|
	
	- size�� byte �����̹Ƿ� 1byte(8bit)

- shift�� ����Ѵٸ� &16������ ���ϴ� �ڸ��� �߶󳻼� ���
```c
	printf("main = flag & 0x01: %d\n", *((unsigned char*)&flagSwitch) & 0x01);
	printf("left = flag & 0x06 >> 1: %d\n", *((unsigned char*)&flagSwitch) & 0x06 >> 1);// ���� ������ ū��(6)�� ����
```


# IV. ����ü
- �� ��� ���� ���� �ؼ����(�ڷ���)�� �ο�
- 32bit ������ ���� int, short[2], char[4]�� �ؼ� ����
- �ʿ��� �κи� �߶󾵶� ���

<table>
	<thead>
		<tr style="background:#000;color:#fff;">
			<th>�ڷ���</th>
			<th>byte</th>
			<th>bit</th>
			<th colspan=8>32bit ����</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="background:#000;color:#fff;">char[8]</td>			
			<td style="background:#000;color:#fff;">1</td>
			<td style="background:#000;color:#fff;">8</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td style="background:#000;color:#fff;">short[4]</td>
			<td style="background:#000;color:#fff;">2</td>
			<td style="background:#000;color:#fff;">16</td>
			<td colspan="2"></td>
			<td colspan="2"></td>
			<td colspan="2"></td>
			<td colspan="2"></td>
		</tr>
		<tr>	
			<td style="background:#000;color:#fff;">int[2]</td>
			<td style="background:#000;color:#fff;">4</td>
			<td style="background:#000;color:#fff;">32</td>
			<td colspan="4"></td>
			<td colspan="4"></td>
		</tr>
	</tbody>
</table>

- �߿��� ����: socket ������ ���� ��������(TCP/IP v4)���� ����ϴ� ������ 32bit
	- IPv6�� ������ ������ v4 ���� ���ǰ� ����
	- 0~255(8bit) 4��
	- ���� ����

## A. ����
- struct�� ���������� typedef�� ���
```c
typedef union _IP_ADDR {
	int nAddress;
	short awData[2];
	unsigned char addr[4];
} IP_ADDR;
```

## B. �ʿ信 ���� ���
- little endian: int�� �����Ҷ� ���� �������� ����� ����

```c
	IP_ADDR Data = { 0 };
	Data.nAddress = 0x41424344;// ABCD
	
	printf("int nAddress\t: %X", Data.nAddress);
	putchar('\n');

	int it = sizeof(Data) / sizeof(char);
	printf("char addr\t: ");
	for(int i=0;i<it;i++)
		printf("%c", Data.addr[i]);
	putchar('\n');
	
	it = sizeof(Data) / sizeof(short);
	printf("short awData\t: ");
	for (int i = 0; i < it; i++)
		printf("%X", Data.awData[i]);
	putchar('\n');
```
>console)
```
int nAddress    : 41424344
char addr       : DCBA
short awData    : 43444142
```

- �޸� ���� �����ϱ�

<table>
	<thead>
		<tr>
			<th colspan=12>96bit(12byte)</th>
		</tr>		
		<tr style="background:#000">
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
			<th>1byte</th>
		</tr>
	</thead>
	<tbody style="text-align: center">
		<tr>
			<td colspan="12" style="color:darkblue;background:aquamarine;">����ü</td>
		</tr>
		<tr>
			<td colspan="4">int</td>
			<td colspan="2">short</td>
			<td colspan="2">short</td>
			<td>ch</td>
			<td>ch</td>
			<td>ch</td>
			<td>ch</td>
		</tr>
		<tr>
			<td colspan="12" style="background: cornsilk;color:darkgoldenrod;">����ü</td>
		</tr>
		<tr>
			<td colspan="4">nAddress</td>
			<td colspan="8" style="background: #000; color: #fff">x</td>
		</tr>
		<tr>
			<td colspan="2">awData</td>
			<td colspan="2">awData</td>
			<td colspan="8" style="background: #000; color: #fff">x</td>
		</tr>
		<tr>
			<td>addr</td>
			<td>addr</td>
			<td>addr</td>
			<td>addr</td>
			<td colspan="8" style="background: #000; color: #fff">x</td>
		</tr>
	</tbody>
</table>


- IP�ּ� ���
```c
	Data.addr[0] = 192;
	Data.addr[1] = 168;
	Data.addr[2] = 0;
	Data.addr[3] = 1;

	printf("address: %d.%d.%d.%d\n", 
		Data.addr[0],
		Data.addr[1],
		Data.addr[2],
		Data.addr[3]
	);
```

> �� IP ã��: ipconfig



[����ü �ǽ� �ڵ�](../c_basic/ch16Struct/.c)

[����ü ��ü �ڵ�](../c_basic/ch16Struct)
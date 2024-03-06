
# I. ���� �ý��� �⺻ �̷�

- computer
	- CPU: �������� ��
	- RAM: 1�� �޸�
	- SSD/HDD: 2�� �޸�

||RAM|SSD<br/>HDD|
|---|---|---|
|�޸�|1�� �޸�|2�� �޸�|
|���Ӽ�|�ֹ߼�|���ֹ߼�|
|�뷮|�ҷ�(8GB~64GB)|�뷮(256GB~2TB)|
|���|����|����|

- ���� �ý��� : 2�� �޸𸮸� �����ϴ� ���
- ������ ������: client������ ����� �� ���� �����͸� ����
	- ���� ���� �ױ� ���� ����Ʈ: [forensic-proof](http://forensic-proof.com/)



## A. �����̶�?
- ������ ���� �ý���(NTFS: New Technology File System)������ �� ����̺� ���� �� ��η� ���
	- ����̺��� ���� ����(Partition)
		- Window programming ��ġ�� ����̺긦 ���� �� �� ����
		- USB(Universal Serial Bus) Disk�� Bootable�� �����ϰ�
		- ���̿������� ����̺긦 ����
		- ���� �� ��ũ�� ����(��� ���� ���·� ���� -> ���� ������ �ֹ� -> ���������� ���� ����)
		- ��ġ
- ������ ��ũ 
	- ����(Disk)
		- ��Ƽ��(Partition)
- ������(����̺꿡�� ����)�� �����(���� Ŀ����ġ ����)
	- Directory(Folder): ���
		- ���� ���(full path): ����̺� ���ؿ��� �����ϴ� ��ü ���
		- ��� ���: ���� Ŀ��(directory ��ġ) �������� �ľ�
			- .  : ���� ���丮
			- .. : ���� ���丮
	- File: ������� ��ġ�� ������ ����
		- ���ϸ�+Ȯ����

|| ���|���ϸ�.Ȯ����|
|---|---|---|
|������|C:\Data\A\ |Hello.c|
|����� (������)|./A/ |Hello.c|
|����� (�������)|../Data/A/ |Hello.c|

- ��δ� �������� ���� �ڷᱸ��
 
## B. ���μ���
- ������ Data ����. 
- ������ ������ ���ü(������ ���)�̶�� �Ѵٸ� ������ ��ü�� Process
- ���ü� �̽�: ���� ���μ����� �����ϴ� �ý��ۿ��� �� ���Ͽ� ���� ���� �����ϴ� ��� �����Ͱ� ��Ű�� ������ �߻��� �� ����
	- �� ���μ����� �� ���Ͽ� �����Ҷ�
		- �����Ͱ� ���Ѽ� ������ �߻��� �� ����(���� �ջ�)
		- �ü��(OS)�� ���μ����� ������ ����
			- ���� ����: R(read)W(write)X(execute) 
			- �� ���ٿ� ���� Open/Close�� ����
			- OS�� ���� ������ ������� �������� ����
## C. ���Ͽ� �����ϴ� ���

- ���� ��/��¿� ���Ǵ� ���� ���۰� ���� �� ����
	- Buffered Input/Output: Ű���� �� ����ߴ� �� 
- ��ġ�� ���Ϸ� �߻�ȭ(User mode Interface)
	- ��ǥ���� �߻�ȭ�� ��: Console(CMD) - �����, Ű���带 �߻�ȭ �س��� ���� ��� �������̽�
	- �߻�ȭ: ������ ���/������ �Ϲ�ȭ, �ܼ�ȭ�� ���� ����ȭ�ϴ� ����
		- ������ ���� : �Ϲ����� �����͸� �����ϴ� ����
		- ��ġ ���� : ��ġ�� �߻�ȭ�� ����
- �ϵ��� �ٷ궧 �߻��ϴ� ���
```
[User mode]		Ž����		word		Excel
			File(�߻�ȭ�� ����: User mode Interface)
---------------------------------------------����

[Kernel mode]		File system	NET

			Filter(�ǽð� ���� ����)


[SW]			Device Driver	
		
---------------------------------------------�ϵ����
		
[HW]			SSD/HDD		NIC(LAN ī��)

```

## D. ���
- ������ ���
- ���� ��ü: ���μ���
- ����: RWX
- �⺻ ����: Open, Close(�ʼ�)
- �߻�ȭ: ��ġ, ������
- ������ ����: OS

## E. ���� ��Ʈ��(File Stream)
### 1. Stream�� Ư¡
- 1���� ���� ����
- ��ƴ���� �����ϴ� ������

- ���
	- �ǽð� ����
	- �ֹ��� �帧���� �̷��� ����
- ����
	- bit stream: bit(0/1)�� �帧
### 2. ���� ��Ʈ��
- ��Ʈ ��Ʈ������ 2�� �޸𸮿� ����� ����. ����(����)�� �������� ����
### 3. 1��, 2�� �޸� ��

||File|RAM|
|---|---|---|
|�����|File stream|malloc(c) - ����޸� ���� �Ҵ�|
|ũ�� �Ҵ�|0���� ������ write�� ũ�Ⱑ �������λ��|����� ����� �޸� ũ�⸦ ����|
|�ڷᱸ��|1���� ��������|�ۼ���|

### 4. ������ �޸� ������ �д� ���
- 1�� �޸��� ������ ����Ÿ� �� �� ������ ���� ��Ʈ���� �ȵ�
- [HxD �ٿ�ε�](https://mh-nexus.de/en/downloads.php?product=HxD20)
![ȭ�� ����](img/hxd_ex.png)
## F. ���ϸ�, Ȯ���, ���̳ʸ��� �ؽ�Ʈ
- ������ �ý��ۿ��� ���ϸ��� ���� �̸� + Ȯ������� ����
- ���� ������ ���̳ʸ��� �ؽ�Ʈ(Binary+text = ASCII code)�� ������
- �ؽ�Ʈ�� ���̳ʸ��� ���ԵǴ� ������ �� �� ����
- �ؽ�Ʈ ������ ���ڿ��� �ؼ��� �� �ִ� ���̳ʸ��� ��� ����
	- ������ �ؼ��� �� ���� Ű: -1
		- copy con���� �Է��ؼ� �����Է��� ����ɶ� Ctrl+z�� �Էµ�
		- �̶� �ԷµǴ� ���� EOF(End Of File). �� ���� -1
		- ����� buffer�� copy con���� -1�� �ԷµǸ� �Է� ��Ʈ���� �����
		- ���� -1�̶�� ���� ���� �Ͱ��� �ٸ�
- 1�� ���� ������ ���޵� bit stream�� �ؼ��� ���ۿ��� �����
	- ��ǻ� ���۵� �ϳ��� ��Ʈ�� 

# II. ���� ����, ����, ���

- fopen()
	- fopen("���ϸ�","���ٸ�� ����")
		- �ش� ������ġ ������(�޸�)�� ��ȯ
	- fopen_s("Path","���ϸ�","���ٸ�� ����");
		- full path�� �Ⱦ��� ���� .sln ������ �ִ� ������ ���� ������ ���Ǿ� ����η� ó��
		- ��ΰ� �߸��Ǹ� ������ �ȵ�
	- ���� �̽��� fopen_s() ���
	- ���� ��� ����: read, write
		- write�� ���� ��Ʈ���� ��(�����) = ���� ���� ����
		- append�� ���� ��Ʈ���� ��(�̾��) = ���� ���� �ڿ�
		- execute�� x

|���|�ǹ�|�����ϴ� ���|���� ���|
|---|---|---|---|
|r|Text read|���� ����|����|
|w|Text write|���� ���� ����� ����|���� ����|
|a|Text append|���� ���� �ڿ� �߰�|���� ����|
|r+|Text read and update|���� ����|����|
|w+|Text write and update|���� ���� ����� ����|���� ����|
|a+|Text append and update|���� ���� �ڿ� �߰�|���� ����|
|rb|Binary read|���� ����|����|
|Wb|Binary write|���� ���� ����� ����|���� ����|
|ab|Binary append|���� ���� �ڿ� �߰�|���� ����|
|rb+|Binary read and update|���� ����|����|
|wb+|Binary write and update|���� ���� ����� ����|���� ����|
|ab+|Binary append and update|���� ���� �ڿ� �߰�|���� ����|

```c
	FILE* fp = NULL;

	fopen_s(&fp, "Test.txt", "w");
	if (fp == NULL) {
		puts("ERROR: Failed to open file!");
		return;
	}
	//TODO: File I/O

	//����� ����
	fclose(fp);
```
- fclose()�� �����ϱ� �������� �ٸ� ���μ������� ��� �Ұ�
- ���ϸ� �����ǰ� ������ ������� 
![���ϻ���](img/fileWrite.png)
- ������ �Է��ϱ�: fprintf(���������, ���Ĺ��ڿ�, �Է�)
	- //TODO: File I/O ��ġ(fopen_s�� fclose ����)�� ���ڿ� ����
```c
//TODO: File I/O
	fprintf(fp, "%s\n", "Hello");
```
- HxD�� ���� ������ ����
	- �Է��� ���ڿ� + \r\n
![hxd�� ���Ϻ���](img/file_textfile.png)
- Enter Ű �Է��� �ΰ���
	- \r + \n: carriage return + line Feed
	- \n: line Feed
- 0D(\r) 0F(\n)�� �˾Ƶθ� ���� ����¶� ���Űǰ��� ����.
	- �׸�ŭ �б� ���� 
	
<table>
	<tbody>
		<tr>
			<th>data</th>
			<td>48</td>
			<td>65</td>
			<td>6C</td>
			<td>6C</td>
			<td>6F</td>
			<td>0D</td>
			<td>0F</td>
		</tr>
		<tr>
			<th>����</th>
			<td>H</td>
			<td>e</td>
			<td>l</td>
			<td>l</td>
			<td>o</td>
			<td>\r</td>
			<td>\n</td>
		</tr>
	</tbody>
</table>

- �ٽ� w�� ȣ���ϸ� ���� ���ϳ����� ������� �ۼ��� �������� ����
	- fopen_s(&fp, "Test.txt", "r+");�� �����
	- fopen_s(&fp, "Test.txt", "a");�� �ڿ� �����̱�
- ���� ���ֻ��
	- ó�� ������ w
	- �� �� �������� ����� a
- _fcloseall(): fopen�� ����� ��Ʈ���� ��� ����
	- return : ��Ʈ�������� Ƚ��
	- ���� �������� ����

# III. �ؽ�Ʈ ���� ��/���
- console I/O�� ũ�� �ٸ��� ����
- ���ϱ���ü�� ���� �����͸� �߰�
## A. character ���
```c
	FILE* filePointer = NULL;
	char ch;
```
- ����
```c
	fopen_s(&filePointer, "Test.txt", "w");
	fputs("Test string!!", filePointer);
	fclose(filePointer);
```
- �б�
```c
	//���� ��Ʈ�� ����
	fopen_s(&filePointer, "Test.txt", "r");
	if (filePointer == NULL)return;//���� ���� ��
	while ((ch = fgetc(filePointer)) != EOF) {//���� ��Ʈ�� ����(-1)���� ����
		putchar(ch);//�ֿܼ� ǥ��
	}
	//���� ��Ʈ�� �ݱ�
	fclose(filePointer);
```
## B. ���ڿ�(string) ���
```c
	FILE* fp = NULL;
	char szBuffer[512] = { 0 };

	fopen_s(&fp, "Test.txt", "w");
	fputs("Test\n", fp);
	fputs("String\n", fp);
	fputs("Data\n",fp);
	fclose(fp);
	
	fopen_s(&fp, "Test.txt", "r");
	if (fp == NULL) return;
	
	// Console(HW)�� �߻�ȭ��Ų CON(user mode file interface) ��� 
	while (fgets(szBuffer, sizeof(szBuffer), fp)) {
		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer));
	}
	printf("����: %d", _fcloseall());
```
- Console(HW)�� �߻�ȭ��Ų CON(user mode file interface)�� ��� ���Ϸ� ����ϸ� �ܼ�â�� ��Ÿ��  
	 - puts�� ���������� ���̰� ����.
```c
	fopen_s(&fp, "CON", "w");
	fputs("Hellow World and CON\n ", fp);
	fclose(fp);
```
- stdout�� ���� ��
```c
	fputs("Hellow World and CON\n", fp);
	puts("Hellow World and CON");
	fputs("Hellow World and CON\n", stdout);
```
- ���� ����ü�� ����Ѵٴ� �� ����� ���̰� ����
```c

	FILE* fp = NULL;
	char szBuffer[512] = { 0 };
	int nData = 0;
	//fprintf
	fopen_s(&fp, "fscanfTest.txt", "w");
	fprintf(fp, "%d,%s\n", 20, "Test");	
	fclose(fp);

	//fscanf_s
	fopen_s(&fp, "fscanfTest.txt", "r");
	fscanf_s(fp, "%d,%s",
		&nData,
		szBuffer,
		(unsigned)_countof(szBuffer)
	);
	fclose(fp);
	
	printf("%d, %s", nData, szBuffer);
```

# IV. Buffered I/O�� ���� ����� ���� �÷���
- �ܼ��� �Է°� ����� �����ϴ� ����� ���� �������̽�
	- stdin, stdout
	- ���� ���۰� �����ϰ� �� ���۸� �ü���� ǥ��
- buffering ���۸�: �޸� ����� ȿ���� ���̱� ���� ���۰� ���� �̻� ���ɶ����� ���. �ӵ��� ����
- flushing �÷���: �������� ��Ʈ�� ��� ��������
```c
	FILE* fp = NULL;
	fopen_s(&fp, "CON", "r"); //stdin
//	fopen_s(&fp, "CON", "w"); //stdout

	char szBuffer[32] = { 0 };
	fgets(szBuffer, sizeof(szBuffer), fp);
	fputs(szBuffer, stdout);
	fflush(stdout);

	fclose(fp);
```
- fflush(): �Է¿����� �÷���
	- ���� clear�� ���ؼ� ���� ���
		- fflush(fp);
	- ǥ�� �Է�(stdin)���� ����..
		- ffluch(stdin); 
- ���� ������ ���� ��ġ(device/HDD, SSD...)�� ���������ϴ� ���� �ƴϴ�
	- OS�� ��Ź�ϸ� OS�� �����쿡 ���� ó��, ����
	- Buffered Input, Output
- �� ���� ���۸� ����ұ�?? 
	- ���������� ��Ʈ���� ������ ����� �������� ���̱� ����
	- live streaming�� ���� ���(������ ����, �Ͻ��� �̻� ��)�� ������ �ð��� Ȯ��

# V. �ܼ� I/O ���� �޸� �����ϱ�
## A. FILE ����ü ���캸��
- io buffer
```c
...
	typedef struct _iobuf
	{
		void* _placeholder;
	} FILE;
...
```
- visual studio�� ������ �ö󰡸鼭 ���� ���캼������ ��
- reverse engineering
```c
typedef struct IOBUF_TEST
{
	char* pCur; // ���� write�� ��ġ
	char* pBase; // ��Ʈ���� ���� ����
	int bufSize; // ��Ʈ�� ũ��
} IOBUF_TEST;
```
- window�� page ������ ó��. �� ũ��� 4KB(4096byte)
- ������ ������ ǥ���ϴ� �Լ�
	- �޸� ��ġ�� �������� ũ�� ����
```c
void print_iobuf(IOBUF_TEST* pBuf) {
	printf("Base\t: %p\n",pBuf->pBase);
	printf("Current\t: %p\n", pBuf->pCur);
	printf("Buffer size\t: %d\n", pBuf->bufSize);
	printf("Written size\t: %zd\n\n",pBuf->pCur - pBuf->pBase);
}
```
- ���� üũ�غ���
```c
	FILE* fp = NULL;

	// ����� ����� ���� ����ü ������ ����
	IOBUF_TEST* ioAddr = (IOBUF_TEST*)fp;

	fopen_s(&fp, "CON", "w");
	print_iobuf((IOBUF_TEST*)fp);

	fputs("Hello", fp);
	print_iobuf((IOBUF_TEST*)fp);

	fputs(" World", fp);
	print_iobuf((IOBUF_TEST*)fp);

	fclose(fp);
```
>console)
```
Base    : 0000000000000000
Current : 0000000000000000
Buffer size     : 0
Written size    : 0

Base    : 000001CC66F62890
Current : 000001CC66F62895
Buffer size     : 4091
Written size    : 5

Base    : 000001CC66F62890
Current : 000001CC66F6289B
Buffer size     : 4085
Written size    : 11

Hello World
```

# VI. ���̳ʸ� ���� ��/���
- binary ������� �� ǥ��("wb")
	- fwrite(Buffer, ElementSize, ElementCount,FILE)
	- fwrite�� �����
```c
typedef struct USERDATA {
	char szName[32];
	char szPhone[32];
} USERDATA;

int main(int argc, char* argv[]) {
	FILE* fp = NULL;
	USERDATA UserData = {"Hong-gil","010-0000-0000"};

	fopen_s(&fp, "TEst.dat", "wb");
	if (fp == NULL) return;
	//(Buffer, ElementSize, ElementCount,FILE)
	fwrite(&UserData, sizeof(USERDATA), 1, fp);

	fclose(fp);
```
![������ Ȯ��](img/file_binaryInput.png)
- ����ü�� ����Ҷ� 64��Ʈ ������ �߶� ����ϸ� ��
	- �ٸ� ����� ����� ��¿ �� ����
- ���Ͽ��� ������ �о����
	- fread(Buffer, size, count, fileStructPointer); 
```c
	memset(&UserData[0], 0, sizeof(UserData));
	fp = NULL;
	fopen_s(&fp, "Test.dat", "rb");
	if (fp == NULL) return;
	//fread(Buffer, size, count, fileStructPointer);
	int it = sizeof(UserData) / sizeof(USERDATA);

	for (int i = 0; i < it; i++) {
		puts("=====");
		fread(&UserData[i], sizeof(USERDATA), 1, fp);
		puts(UserData[i].szName);
		puts(UserData[i].szPhone);
	}

	fclose(fp);
```
- stream�� �ܹ��� �帧�̶� �Է°� ����� ������ �� ����
>console)
```
=====
Hong-gil
010-0000-0000
=====
Kong-gil
010-1111-0000
=====
Jong-gil
010-2222-0000
```
- ����!!
	- ���ڿ��� ���� ��Ÿ���� 0D 0F(\r\n)
	- ���� ũ�Ⱑ 32 �ΰ�� ������ �߻�
	- �Է��� �ŷ��������� ������ ����
		- ���, �ʰ� ������ ��

# VII. ���� ��/��� ������ ��ġ ����
## A. ���� ����
- FILE*�� ���ϴ°� �ƴ�!!
	- ������� �߻��ϴ� ��ġ(index) ����

<table style="text-align:center">
	<thead>
		<tr>
			<th colspan="10">File stream</th>
		</tr>
		<tr>
			<th>Base</th>
			<th></th>
			<th></th>
			<th></th>
			<th></th>
			<th>Cur</th>
			<th>
				<span style="color:red">p</span>
			</th>
			<th></th>
			<th></th>
			<th>End</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>H</td>
			<td>e</td>
			<td>l</td>
			<td>l</td>
			<td>o</td>
			<td>\0</td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
	</tbody>

</table>

- �� ��ġ�� �����Ҷ� ���� �Լ�: fseek
	-  binary mode������ �۵�: wb/rb/ab
	- fseek(filePointer, Offset-���������� �̵���ġ, Origin-������)
- fseek()�� ���� ������(in stdio.h)
```
#define SEEK_CUR    1 ����ġ
#define SEEK_END    2 ����
#define SEEK_SET    0 ������

#define FILENAME_MAX    260
#define FOPEN_MAX       20
#define _SYS_OPEN       20
#define TMP_MAX         _CRT_INT_MAX
#if __STDC_WANT_SECURE_LIB__
    #define TMP_MAX_S       TMP_MAX
    #define _TMP_MAX_S      TMP_MAX
#endif
```
- ftell(filePointer): base~current������ ũ�⸦ ��ȯ
```c
	FILE* fp = NULL;
	
	fopen_s(&fp, "Test.dat", "rb");

	fseek(fp, 0, SEEK_END);
	printf("size of Test.dat: %u\n", ftell(fp));

	fclose(fp);
```
>console)
```
size of Test.dat: 192
```
## B. ����
```c
	FILE* fp = NULL;
	char* pszData = "01234567890123456789012345678901";//32byte

	fopen_s(&fp, "TestP.dat", "wb");
	if (fp == NULL) return;

	fwrite(pszData, 32, 1, fp);
	printf("current File pointer: %u\n", ftell(fp));

	fseek(fp, 5, SEEK_SET);//���� ������ �̵�
	printf("current File pointer: %u\n", ftell(fp));

	fwrite("Hello", 5, 1, fp);//�� ��ġ���� �Է�
	printf("current File pointer: %u\n", ftell(fp));

	fclose(fp);
```
![�������̵�](img/file_binaryIO_seekPointer.png)
>console)
```
current File pointer: 32
current File pointer: 5
current File pointer: 10
```

- ���־������� ������ �ʿ��Ҷ� ã�� ����ϸ� ��

��������� C����� ����
---
- ���ķδ� �ణ ����̷�. �˾Ƶθ� ���� �͵�








[���� �ý��� �ǽ� �ڵ�](../c_basic/ch17FileSystem/.c)

[���� �ý��� ��ü �ڵ�](../c_basic/ch17FileSystem)
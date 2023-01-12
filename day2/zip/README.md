## ZIP program

### compress

1. NIV.txt를 읽는다.
2. 각각의 char_freq를 count한다.
3. frequency가 높은 15개 char를 알아낸다.
   이를 top_char[]에 순서대로 저장.
4. my_encode_head를 통해 output (NIV.txt.myzip) 헤더에
   압축될 문자 개수와, 압축한 문자들을 freq 순서대로 나열한다.
5. my_encode_body를 통해
   top_char문자들을 하나하나씩 encoding한다.

#### 추가된 코드

```c
void compress_file(char* filename)  {
  ...
    char top_char[15] = {0};
  ...
    
    count_ascii_freq(char_freq, filename);
  	get_top_char(char_freq, top_char, 15);
  ...
   	my_encode_head(output, 15, top_char);
}


void get_top_char(int* char_freq, char* top_char, int size) {
  이 함수에서는 top_char에 size개 개수만큼 빈도수가 가장 높은 문자들을 size개 모은다.
}

void my_encode_head(FILE* output, int count, char* top) {
  이 함수에서는 NIV.txt.myzip 파일에 맨 처음 입력될 내용으로, head파트라고 부른다.
    head는 압축될 char의 개수가 입력되고, 각각 1위부터 15위까지 char가 순차적으로 입력된다.
    ex
    15_eaigf...
    (_는 스페이스)
}
```

해당 compress를 진행하면 NIV.txt.myzip 파일은 head부분과 body부분으로 나뉘어진다.

- head는 압축된 문자의 개수와 압축된 문자들이 적혀있고,
- body에는 실제로 NIV.txt를 압축한 내용이 적히게 된다.



### decompress

1. NIV.txt.myzip 파일을 읽는다.
2. my_decode_head() 함수를 통해 top_char를 알아낸다.
   NIV.txt.myzip에 맨 처음에 있는 데이터 참조해서(head부분)
3. Binary tree를 만든다. (15개라면 16개 만들어야하니, 4층짜리 tree를 만들면 되겠죠?)
4. 각 Binary tree에 terminal 노드를 맨 왼쪽부터 차례대로 top_char들을 넣어준다.
   TreeNode의 데이터가 char가 되는 겁니다.
5. NIV.txt.myzip의 body부분을 읽어서 하나씩 버퍼에 넣는다.
   1. 새롭게 decode할때, 처음 bit가 0이라면, 그대로 8개의 bit를 읽어서 출력하면 되고,
   2. 새롭게 decode할때, 처음 bit가 1이라면, 3-4번에서 만든 tree를 따라 이동하면서 terminal node를 만날때 까지 이동하여 해당 data를 알아낸다.
      - 만일 다음 비트가 1이라면, 오른쪽 child으로 이동.
      - 만일 다음 비트가 0이라면, 왼쪽 child로 이동.
        - 이동된 비트가 terminal이라면, 즉 left child와 right child가 모두 NULL이라면, 데이터 읽기
6. 5번을 반복하여, 한 문자씩 decompress하고, EOF를 만나면 stop

#### 추가된 코드

```c
void decompress_file(char* filename) 
{
	  char* top_char;
  ...
    my_decode_head(input, &numOfChar, &top_char);
  	my_decode_body(input, output, numOfChar, top_char);
}
```


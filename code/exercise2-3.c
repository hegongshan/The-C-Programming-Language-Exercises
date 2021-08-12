#include <stdio.h>
#include <assert.h>

int htoi(char const s[])
{
	int i = 0;
	int n = 0;
	int base = 16;

	// 处理可选的前缀0x或者0X
	if (s[i] == '0') {
		i++;
		if (s[i] == 'x' || s[i] == 'X') {
			i++;
		}
	}
	
	// 参照K&R P33 atoi函数
	int valid = 1;
	while (valid && s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9') {
			n = base * n + s[i] - '0';
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			n = base * n + s[i] - 'a' + 10;
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			n = base * n + s[i] - 'A' + 10;
		} else {
			valid = 0;
		}
		i++;
	}
	return n;
}

int main(int argc, char const *argv[])
{
	assert(htoi("0") == 0);
	assert(htoi("11") == 17);
	
	assert(htoi("0x12") == 18);
	assert(htoi("0X13") == 19);
	assert(htoi("0x1f") == 31);
	assert(htoi("0xff") == 255);

	assert(htoi("0xiii") == 0);
	assert(htoi("0x1j") == 1);
	return 0;
}
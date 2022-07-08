#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int hour;
	int min;
	int sec;
}TIME;

TIME elapsedTime(TIME, TIME);

int main()
{
	TIME start, end;
	scanf("%d:%d:%d", &start.hour, &start.min, &start.sec);
	scanf("%d:%d:%d", &end.hour, &end.min, &end.sec);
	TIME ans = elapsedTime(start, end);
	printf("%02d:%02d:%02d", ans.hour, ans.min, ans.sec);

	return 0;
}

TIME elapsedTime(TIME start, TIME end)
{
	TIME ans;
	ans.hour = end.hour - start.hour;
	ans.min = end.min - start.min;
	ans.sec = end.sec - start.sec;

	if (ans.sec >= 60)
	{
		ans.min += ans.sec / 60;
		ans.sec %= 60;
	}
	else
	{
		ans.min -= 1;
		ans.sec += 60;
	}

	if (ans.min > 0)
	{
		ans.hour += ans.min / 60;
		ans.min %= 60;
	}
	else
	{
		ans.hour -= 1;
		ans.min += 60;
	}


	return ans;
}
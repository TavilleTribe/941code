//两个乒乓球队进行比赛，各出3人。甲队为A,B,C 3人，乙队为X,Y,Z 3人
//以抽签决定比赛名单。有人向队员打听比赛名单，A说他不和X比，C说他不和X,Z比
//请编程序找出3对赛手名单
int main()
{
	int a, b, c;  //a是A的对手 b是B的对手 c是C的对手
		for (a = 'X'; a <= 'Z'; a++)
		{
			for (b = 'X'; b <= 'Z'; b++)
			{
				if (a != b)//避免重复比赛
				{
					for (c = 'X'; c <= 'Z'; c++)
				    {
						if (a != c&&b!=c)//避免重复比赛
						{
							if (a != 'X' && c != 'X' && c != 'Z')
							{
								printf(" A对%c\n B对%c\n C对%c", a, b, c);
							}
						}
					}
				}
			}	
		}	
	return 0;


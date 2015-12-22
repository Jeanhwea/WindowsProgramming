// KernelObject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/** 读书笔记：
    1. 内核对象可以通过一个免费的工具WinObj查看，必须要使用管理员权限运行WinObj
       才能查看内核对象。
    2. 区分内核对象和用户对象的最简单方法是查看创建这个函数的签名。几乎所有的内核对象
       的创建函数需要我们在创建时给出安全属性信息的参数。
 */
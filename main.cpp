//�������� 1:
// enum class
// initializer_list � ������������� ������ �������������
// auto
// decltype
// lambda 
// template variable

#include "print.h"





int main()
{
	//������� 1. 
	{
		enum class months : unsigned char { January, February, March/*...*/ };
		enum class weekDays { Monday, Tuesday /*...*/ };

		months m = months::January;
		//�) ������� �������� (��� ������, ��� ���������� ��
		//������ ��������� ������������ ������������ �������
		//���������!)

		//if (m == weekDays::Monday) { /*...*/ }

		//�) ������������� ������������� ������
		months year[] = { months::January, months::February, months::March };
		size_t n = sizeof(year); //???

		__asm nop
	}


	/**********************************************************/
		//������� 2. �������� � � ������� ������ �������������
		//��������� ���������� ������ � ���������� - string
		//� ������� range-based for ������������ ��� ����� � 	
		//������� ������� � ��������� ������� ������ ��������
		//�����������
	{
		std::vector<std::string> vStr1{ "oNe", "tw0", "Thr33" };
		for (std::string i : vStr1) {
			transform(i.begin(), i.end(), i.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c); });
		}
		__asm nop
	}


	/**********************************************************/
		///������� 3. �������� � ��������� ����������
		//map ����� ��������� (3� � 3�) ����� �������, ����� �� �������� 
		//� �������� ����� �����, � � �������� �������� 
		//��������������� �� �������� ������������ ���� (string), 
		//������������ � ���� �����

		//3�. ������������������ map "�������" ����������� ������ �������������
		//� ������� range-based for � structured binding
		//������������ ����������, ��������: A: any, apple, away
	{
		std::map<char, std::set<std::string>> Dict{
		{'a', {"advantage", "awesomeness", "apple"}},
		{'b', {"bible", "book", "bar"}},
		{'c', {"circle", "curry", "case"}}
		};
		for (const auto& [first, second] : Dict) {
			std::cout <<first << ": " << second << std::endl;
		}

		__asm nop
	}

	//3�. �������� ������ map � ����������� �������� ������
	//��� ���������� �������.
	//� ������� range-based for � structured binding
	//������������ ����������, ��������: A: any, apple, away
	{
		//���� (��������):
		const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };
		std::map<char, std::set<std::string>> Dict;
		for (size_t i = 0; i < (sizeof(s) / sizeof(s[0])); i++) {
			Dict[(s[i])[0]].insert(std::string(s[i]));
		}
		for (const auto& [first, second] : Dict) {
			std::cout << first << ": " << second << std::endl;
		}

		__asm nop
	}


	/*********************************************************/
		//������� 4. ������� ������� ��� ������ �� ������
		//��������� �������������������, �������� ����:
	{
		std::vector<double> vd = { 1.1,2.2,3.3 };
		PrintAnyCont(vd);

		std::string s("abc");
		PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		PrintAnyCont(ar);

		std::initializer_list<int> il{ 3,4,5 };
		PrintAnyCont(il);		

		__asm nop
	}


	/********************************************************/
		///������� 5. 	
		//C������ ������� ��� "���������" ��������, ��������:
		//����: {1, -2, 5}, �����: {-1, 2, -5})
		//��������� �������� ���� std::string ����� ��������� "aBc1" -> "AbC1"
		//��������� �������������������, �������� ����:
	{
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);

		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);

		int ar[]{ 1, 2, 3 };
		NegateAll(ar);

		__asm nop

	}


	/********************************************************/
		//������� 6. ����������� ������� ���������� �� ������
		//��������� �������������������, �������� ����
		//���������� ��� ���������� ����� ������������ ����������
		//�������� sort(), � ��� ������� ������� - ������-�������
	{
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		absSort(vd);


		int ar[] = { -3, 2, -1 };
		absSort(ar);

		__asm nop
	}


	/********************************************************/
		//������� 7.
		//�������� �������, ������� ����� ����������� �
		//���������� ������, ������ ������� 
		//�������� �������� ������ ��������� ���� 
		//������������������� ������ �����
		//� � ���������� ������� ����.

		//��������� 1: ��� ��� ������������������ ����� ����
		//������ �����, ������� ������� ������ ���������������
		//������� ������������ �� ����

		//��������� 2: ��������� � ����������� �������������
		//���������� copy() � transform(), � ������� 
		//���������������� �������� ������ � ���� �������
		//�������� ������-��������

		//��������:
	{
		std::vector<int> v{ 1,2,3,4 };
		std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };

		auto vv = SumCont(v, l);
		PrintAnyCont(vv);

		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		auto vv1 = SumCont(ar, ll);
		PrintAnyCont(vv1);

		std::set<std::string> s{ "abc", "qwerty", "my" };
		std::deque<const char*> d{ "111", "22" };
		auto vv2 = SumCont(s, d);
		PrintAnyCont(vv2);
		__asm nop
	}


	/********************************************************/
		//������� 8. ���������� �������, ������� ��������� ��������� ���������:	
		//�������������� ������������������ ������ ���� � ���������� ������ ����, 
		//��� (������) ���������� ������ ���� �� vector, list, deque, set 
		//� ���������� ���� �� ����, ��� � � �������������� ������������������ 

		//������� ������ "���������" �������� �������� ������������������ � ��� ������ ���������� 
		//�������� ��������� �������. ������� ������ �����-��������
		//�������� ������������������ ��� ���� �� ��������
	{
		//��������:
		std::vector<int> v{ 1,2,3,4,5 };
		std::list<int> l; //���� ������
		std::deque<int> d; //� ���� ��������
		Separate(v, l, d, [](const int& val) { return !(val & 1); });

		__asm nop
	}


	/********************************************************/
		//������� 9. C ������� ��������� for_each()!!! 
		//(� �� count_if()) ��������� ������� ���� � �������
		//��������.
		//  ������������ ������ �������
	{
		char s[] = "Hello World!";
		size_t c = 0;
		std::for_each(std::cbegin(s), std::cend(s), [&c](const auto& ch) { if (std::isupper(ch)) { c++; }; });
		std::cout << c << std::endl;


		__asm nop
	}


	/********************************************************/
		//������� 10. ����������� ����������� enum � ��������� �������������  - enumToString
		// � �������� - stringToEnum

		//���������: 
		//***********
		//1. ��������������� ����������� ���������� ������ ��� ����� ����� ���-�� ������� =>
		//1.1 ����������� ��������� � ������������ ������ ���� ����������� => ��������������� ������
		//���� ������ ���� �����������, => ���������� ������ ����� ���� ������������ � ��������
		//����� � std::map

		//1.2 � ��� �������� (��������������� ���������� ����������)
		//����� ���� ������ � ���� ����� ����������� (�������� ������, ������, ��� �������� �� �����������) 
		//=> �������� ��������� std::map<string,<��������> >

		//1.3 �������� ��������� �++11 ���������� ������������� ���� ����� ���� ������� ������� � ����,
		//� �������� �� ���������� ������������� ����������� 

		//***********
		//2.1 ��� ��� ���� ������������ ������, �� enumToString � stringToEnum ������ ���� ����������
		//2.2 ������������ ����� ��������� ��� ������������ �������� � ������� ��������, �������
		//   ������ �� ������������� => ������!


		//***********
		//3. ����� �������� � map<string, <��������> > �� �������� �� ���� ������������, ��������� ��� ��������������
		//��������� ���������� (� ��������� ��������� � ����������� ������������� ��������� ����������)


		//***********

	{
		COLORS c1;
		try {
			c1 = stringToEnum<COLORS>(std::string("blue"));      // vector::at throws an out-of-range
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
		
		//auto Str = enumToString(c1, data);
		auto Str = enumToString(c1);
		//��������:
	/*
			COLORS c1;
			try {
				c1 = stringToEnum<COLORS>("blue");
			}
			catch (...)
			{
			//...
			}


			auto Str = enumToString(c1);
	*/

		__asm nop
	}

	return 0;
}

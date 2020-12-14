#include "pch.h"
#include "CppUnitTest.h"
#include "../Project11.2.А/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			student s;

			fstream file_s("C:\\Моя папка\\Student [Tkachenko.Marharyta.IK-11]\\Lab_11.2.A\\Lab_11.2.A\\test", ios::binary);

			s.prizv = "tit";
			s.kurs = 3;
			s.specialization = (Special)4;
			s.phisuka = 5;
			s.matematic = 5;
			s.informatic = 4;

			file_s.write((char*)&s, sizeof(student));
			file_s.close();

			file_s.open("C:\\Моя папка\\Student [Tkachenko.Marharyta.IK-11]\\Lab_11.2.A\\Lab_11.2.A\\test", ios::binary);

			s.prizv = "rir";
			s.kurs = 1;
			s.specialization = (Special)3;
			s.phisuka = 2;
			s.matematic = 3;
			s.informatic = 4;

			file_s.write((char*)&s, sizeof(student));
			file_s.close();

			ifstream file_ll("C:\\Моя папка\\Student [Tkachenko.Marharyta.IK-11]\\Lab_11.2.A\\Lab_11.2.A\\test", ios::binary);
			double l = find_prozent(s, 3, file_ll);
			file_ll.close();

			Assert::AreEqual(l, 0.);
		}
	};
}

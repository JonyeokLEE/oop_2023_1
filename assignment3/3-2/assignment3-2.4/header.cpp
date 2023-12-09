#include "header.h"

Term::Term() //������
{
	m_Coefficient = 0;
	m_Exponent = 0;
	m_pNext = nullptr; //���� �ʱ�ȭ
}

Term::~Term() //�Ҹ���
{
}

void Term::SetCoeff(int coeff) //SetCoeff �Լ�
{
	m_Coefficient = coeff; //coeff�� ����
}

void Term::SetExponent(int exponent) //SetExponent �Լ�
{
	m_Exponent = exponent; //exponent�� ����
}

int Term::GetCoeff() //GetCoeff �Լ�
{
	return m_Coefficient; //��� ��ȯ
}

int Term::GetExponent() //GetExponent �Լ�
{
	return m_Exponent; //���� ��ȯ
}

void Term::SetNext(Term* pNext) //SetNext �Լ�
{
	m_pNext = pNext; //pNext ����
}

Term* Term::GetNext() //GetNext �Լ�
{
	return m_pNext; //m_pNext ��ȯ
}

Polynomial::Polynomial()
{
	m_pHead = nullptr;
	varible = 0; //���� �ʱ�ȭ
}

Polynomial::~Polynomial() //�Ҹ���
{
}

void Polynomial::Insert(Term* pTerm) //Insert �Լ�
{
	if (m_pHead == nullptr || m_pHead->GetExponent() < pTerm->GetExponent())
	{	//����Ʈ�� �ƹ��͵� ���ų� head�� ������ �� ����� �������� ������
		pTerm->SetNext(m_pHead); //�� ����� ���� ��带 head��
		m_pHead = pTerm; //head�� pTerm�� ����Ų��.
		//�� ����Ʈ �� �տ� �����ϴ� ����!
	}
	else //�� ���� ���
	{	//�˸´� �ڸ��� ã�� ����
		Term* curr = m_pHead; //head���� ����
		while (curr->GetNext() != nullptr && curr->GetNext()->GetExponent() > pTerm->GetExponent())
			curr = curr->GetNext(); //curr�� ������尡 �ְų�, �� ���� ����� ������ �� ����� �������� Ŭ ���� ��� �̵�
		pTerm->SetNext(curr->GetNext()); //pTerm�� ���� ��带 curr�� ���� ���� ����
		curr->SetNext(pTerm); //curr�� ���� ��带 pTerm���� ����
	}
}

void Polynomial::PrintList() //PrintList �Լ�
{
	for (Term* curr = m_pHead; curr != nullptr; curr = curr->GetNext())
	{	//ó������ ������ ���
		cout << curr->GetCoeff() << varible << "^" << curr->GetExponent(); //r����� ������ ���� ���
		if ((curr->GetNext() != nullptr)&&(curr->GetNext()->GetCoeff()>0))//�ڿ��� ���� �ƴϰ� ���� ��Ұ� ������
		{
				cout << "+"; //+���
		}
	}
	cout << endl;
}

void Polynomial::setvarible(char set) //setvarible �Լ�
{
	varible = set; //set ����
}

void Polynomial::Add(Polynomial& poly) //Add �Լ�
{
	Term* curr1 = m_pHead; //curr1�� �� 1�� head
	Term* curr2 = poly.m_pHead; //curr2�� �� 2�� head���� ����
	Polynomial result; //������� �޴� �Լ�

	while (curr1 != nullptr && curr2 != nullptr) //�� �� �ϳ��� ������ ������
	{
		if (curr1->GetExponent() == curr2->GetExponent()) //���� ������ ������
		{
			int add = curr1->GetCoeff() + curr2->GetCoeff(); //�� ����� ���� ���� ����
			if (add != 0) //���� ���� 0�� �ƴϸ�
			{
				Term* temp = new Term; //�� ��� ����
				temp->SetCoeff(add); //���� ���� ����� ����
				temp->SetExponent(curr1->GetExponent()); //������ ������ �״�� ����
				result.Insert(temp); //temp�� result�� �ֱ�
			}
			curr1 = curr1->GetNext();
			curr2 = curr2->GetNext(); //�Ѵ� ���� ����
		}
		else if (curr1->GetExponent() > curr2->GetExponent()) //���� curr1�� ������ �� ũ��
		{
			Term* temp = new Term; //�� ��� ����
			temp->SetCoeff(curr1->GetCoeff());
			temp->SetExponent(curr1->GetExponent()); //curr1�� ���� �ޱ�
			result.Insert(temp); //temp�� result�� ����
			curr1 = curr1->GetNext(); //���� ����
		}
		else
		{
			Term* temp = new Term; //�� ��� ����
			temp->SetCoeff(curr2->GetCoeff());
			temp->SetExponent(curr2->GetExponent()); //curr2�� ���� �ޱ�
			result.Insert(temp); //temp�� result�� ����
			curr2 = curr2->GetNext(); //���� ����
		}
	}

	while (curr1 != nullptr) //curr1�� ���� ��������
	{
		Term* temp = new Term; //�� ��� ����
		temp->SetCoeff(curr1->GetCoeff());
		temp->SetExponent(curr1->GetExponent()); //curr1�� ���� �ޱ�
		result.Insert(temp); //temp�� result�� ����
		curr1 = curr1->GetNext(); //���� ����
	}

	while (curr2 != nullptr) //curr2�� ���� ��������
	{
		Term* temp = new Term; //�� ��� ����
		temp->SetCoeff(curr2->GetCoeff());
		temp->SetExponent(curr2->GetExponent()); //curr2�� ���� �ޱ�
		result.Insert(temp); //temp�� result�� ����
		curr2 = curr2->GetNext(); //���� ����
	}

	m_pHead = result.m_pHead; //result head�� ����
}

void Polynomial::Sub(Polynomial& poly)
{
	Term* curr1 = m_pHead; //curr1�� �� 1�� head
	Term* curr2 = poly.m_pHead; //curr2�� �� 2�� head���� ����
	Polynomial result; //������� �޴� �Լ�

	while (curr1 != nullptr && curr2 != nullptr) //�� �� �ϳ��� ������ ������
	{
		if (curr1->GetExponent() == curr2->GetExponent()) //���� ������ ������
		{
			int sub = curr1->GetCoeff() - curr2->GetCoeff(); //�� ����� ���� ���� ����
			if (sub != 0) //���� ���� 0�� �ƴϸ�
			{
				Term* temp = new Term; //�� ��� ����
				temp->SetCoeff(sub); //���� ���� ����� ����
				temp->SetExponent(curr1->GetExponent()); //������ ������ �״�� ����
				result.Insert(temp); //temp�� result�� �ֱ�
			}
			curr1 = curr1->GetNext();
			curr2 = curr2->GetNext(); //�Ѵ� ���� ����
		}
		else if (curr1->GetExponent() > curr2->GetExponent()) //���� curr1�� ������ �� ũ��
		{
			Term* temp = new Term; //�� ��� ����
			temp->SetCoeff(curr1->GetCoeff());
			temp->SetExponent(curr1->GetExponent()); //curr1�� ���� �ޱ�
			result.Insert(temp); //temp�� result�� ����
			curr1 = curr1->GetNext(); //���� ����
		}
		else
		{
			Term* temp = new Term; //�� ��� ����
			temp->SetCoeff(-1*curr2->GetCoeff()); //2�� ���� ���� ���̴� ���� ���̱�
			temp->SetExponent(curr2->GetExponent()); //curr2�� ���� �ޱ�
			result.Insert(temp); //temp�� result�� ����
			curr2 = curr2->GetNext(); //���� ����
		}
	}

	while (curr1 != nullptr) //curr1�� ���� ��������
	{
		Term* temp = new Term; //�� ��� ����
		temp->SetCoeff(curr1->GetCoeff());
		temp->SetExponent(curr1->GetExponent()); //curr1�� ���� �ޱ�
		result.Insert(temp); //temp�� result�� ����
		curr1 = curr1->GetNext(); //���� ����
	}

	while (curr2 != nullptr) //curr2�� ���� ��������
	{
		Term* temp = new Term; //�� ��� ����
		temp->SetCoeff(-1*curr2->GetCoeff()); //2�� ���� ���� ���̴� ���� ���̱�
		temp->SetExponent(curr2->GetExponent()); //curr2�� ���� �ޱ�
		result.Insert(temp); //temp�� result�� ����
		curr2 = curr2->GetNext(); //���� ����
	}

	m_pHead = result.m_pHead; //result head�� ����
}

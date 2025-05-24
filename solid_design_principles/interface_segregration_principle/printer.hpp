#pragma once
#include<iostream>
using namespace std;


class Document;

class IMachine_Interface 
{
	virtual void print(Document& doc) = 0;
	virtual void scan(Document& doc) = 0;
	virtual void fax(Document& doc) = 0;
};

class MFP : public IMachine_Interface
{
	void print(Document& doc) override
	{

	}
	void scan(Document& doc) override
	{

	}
	void fax(Document& doc) override
	{

	}

};

class IPrinter
{
public:
	virtual void print(Document& doc) = 0;
};

class IScanner
{
public:
	virtual void scan(Document& doc) = 0;
};

class IFax
{
public:
	virtual void fax(Document& doc) = 0;
};

class Printer : public IPrinter
{
public:
	void print(Document& doc) override
	{

	}
};

class Scanner : public IScanner
{
public:
	void scan(Document& doc) override
	{

	}
};


class Machine : public IPrinter, IScanner
{
public:
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter& printer, IScanner& scanner): printer(printer), scanner(scanner){}

	void print(Document& doc) override
	{
		this->printer.print(doc);
	}
	void scan(Document& doc) override
	{
		this->scanner.scan(doc);
	}
};


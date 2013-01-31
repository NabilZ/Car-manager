#ifndef FORMS_H
#define FORMS_H

#include "mainwindow.h"

void MainWindow::add_client_form()//форма добавления клиента
{
    QDialog *dialog = new QDialog(this);

	QLabel *lblicense_num = new QLabel(tr("Rights"),dialog);
    QLabel *lbsurname = new QLabel(tr("Surname"),dialog);
    QLabel *lbfistname = new QLabel(tr("Firstname"), dialog);
    QLabel *lbmiddlename = new QLabel(tr("Middlename"), dialog);
	QLabel *lbpasport_num = new QLabel(tr("Passport number"),dialog);
    QLabel *lbadr = new QLabel(tr("Adress"),dialog);

    lelicense_num = new QLineEdit(dialog);
    lesurname = new QLineEdit(dialog);
    lefirstname = new QLineEdit(dialog);
    lemiddlename = new QLineEdit(dialog);
    lepasport_num = new QLineEdit(dialog);
    leadr = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

	dialog->setGeometry(200,200,250,200);
    dialog->setWindowTitle(tr("Add Client"));

    lblicense_num->setGeometry(5,5,90,20);
    lbsurname->setGeometry(5,25,90,20);
    lbfistname->setGeometry(5,45,90,20);
    lbmiddlename->setGeometry(5,65,90,20);
	lbpasport_num->setGeometry(5,85,120,20);
    lbadr->setGeometry(5,105,90,20);

	lelicense_num->setGeometry(125,5,90,20);
	lesurname->setGeometry(125,25,90,20);
	lefirstname->setGeometry(125,45,90,20);
	lemiddlename->setGeometry(125,65,90,20);
	lepasport_num->setGeometry(125,85,90,20);
	leadr->setGeometry(125,105,90,20);

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    lelicense_num->setInputMask("99 AA 999999");
    lepasport_num->setInputMask("99 99 999999");

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()), dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(add_client()));
	dialog->connect(ok, SIGNAL(clicked()), dialog,SLOT(close()));
}

void MainWindow::view_client_form()//форма просмотра клиентов
{
    QDialog *dialog = new QDialog;

    int i=0;

	tableWidget = new QTableWidget(100,7,dialog);
    QStringList list;
	list << tr("Rights") << tr("Surname") << tr("Firstname") << tr("Middlename") << tr("Passport number") << tr("Adress") << tr("Use service count");
    tableWidget->setHorizontalHeaderLabels(list);

	dialog->setGeometry(300,300,760,400);
    dialog->setWindowTitle(tr("View Client"));
    dialog->show();

	tableWidget->setGeometry(0,0,760,400);
    tableWidget->show();

    view_client(this->client,i);
}

void MainWindow::remove_client_form()//форма удаления клиента
{
    QDialog *dialog = new QDialog;

	QLabel *lblicense_num = new QLabel(tr("Rights"),dialog);

    lelicense_num = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(300,300,200,200);
    dialog->setWindowTitle(tr("Remove Client"));

    lblicense_num->setGeometry(5,5,90,20);

    lelicense_num->setGeometry(95,5,90,20);
    lelicense_num->setInputMask("99 AA 999999");

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()), dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(del_client()));
	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
}

void MainWindow::search_client_form()//форма поиска клиента
{
    QDialog *dialog = new QDialog(this);

	QLabel *lblicense = new QLabel(tr("Rights"),dialog);
    QLabel *lbsurname = new QLabel(tr("Surname"),dialog);
    QLabel *lbfistname = new QLabel(tr("Firstname"),dialog);
    QLabel *lbmiddlename = new QLabel(tr("Middlename"),dialog);

    lelicense_num = new QLineEdit(dialog);
    lesurname = new QLineEdit(dialog);
    lefirstname = new QLineEdit(dialog);
    lemiddlename = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(200,200,200,200);
    dialog->setWindowTitle(tr("Search Client"));

    lblicense->setGeometry(5,25,90,20);
    lbsurname->setGeometry(5,45,90,20);
    lbfistname->setGeometry(5,65,90,20);
    lbmiddlename->setGeometry(5,85,90,20);

    lelicense_num->setGeometry(95,25,90,20);
    lelicense_num->setInputMask("99 AA 999999");
    lesurname->setGeometry(95,45,90,20);
    lefirstname->setGeometry(95,65,90,20);
    lemiddlename->setGeometry(95,85,90,20);

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()), dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(search_client_for_form()));
	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
}

void MainWindow::search_client_for_form()
{
    QDialog *dialog = new QDialog;

    int i=0;

    tableWidget = new QTableWidget(100,7,dialog);
    QStringList list;
	list << tr("Rights") << tr("Surname") << tr("Firstname") << tr("Middlename") << tr("Passport number") << tr("Adress") << tr("Car gos number");
    tableWidget->setHorizontalHeaderLabels(list);

    dialog->setGeometry(300,300,500,400);
    dialog->setWindowTitle(tr("View Client"));
    dialog->show();

    tableWidget->setGeometry(0,0,500,400);
    tableWidget->show();

    search_client_for(this->client, i);
}

void MainWindow::show_client_form()  //главная форма клиентов
{
    client_form = new QWidget;
    comboclient = new QComboBox(client_form);

    client_form->show();
    client_form->setGeometry(300,200,300,300);
    client_form->setMaximumSize(300,300);
	client_form->setWindowTitle(tr("Clients"));

	comboclient->setGeometry(90,0,150,25);
	comboclient->addItem(tr(""));
    comboclient->addItem(tr("registration client"));
    comboclient->addItem(tr("remove client"));
    comboclient->addItem(tr("view clients"));
    comboclient->addItem(tr("clear data"));
    comboclient->addItem(tr("search client"));

	connect(comboclient, SIGNAL(currentIndexChanged(QString)), this, SLOT(change_comboclient()));
}

void MainWindow::add_car_form()     //форма добавления автомобиля
{
    QDialog *dialog = new QDialog;

    QLabel *lbnumber = new QLabel(tr("gos number"),dialog);
    QLabel *lbmark = new QLabel(tr("mark"),dialog);
    QLabel *lbcolor = new QLabel(tr("color"),dialog);
    QLabel *lbyear = new QLabel(tr("year"),dialog);

    lenumber = new QLineEdit(dialog);
    lemark = new QLineEdit(dialog);
    lecolor = new QLineEdit(dialog);
    leyear = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(400,300,200,200);
    dialog->setWindowTitle(tr("Add Auto"));

    lbnumber->setGeometry(5,5,90,20);
    lbmark->setGeometry(5,25,90,20);
    lbcolor->setGeometry(5,45,90,20);
    lbyear->setGeometry(5,65,90,20);

    lenumber->setGeometry(95,5,90,20);
    lemark->setGeometry(95,25,90,20);
    lecolor->setGeometry(95,45,90,20);
    leyear->setGeometry(95,65,90,20);

    lenumber->setInputMask("A999AA-99");
    leyear->setInputMask("0000");

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()), dialog,  SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(add_car()));
	dialog->connect(ok, SIGNAL(clicked()), dialog,SLOT(close()));
}

void MainWindow::remove_car_form()  //форма удаления автомобиля
{
    QDialog *dialog = new QDialog;

    QLabel *lbnumber = new QLabel(tr("gos number"),dialog);

    lenumber = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(400,300,200,200);
	dialog->setWindowTitle(tr("Remove car"));

    lbnumber->setGeometry(5,5,90,20);

    lenumber->setGeometry(95,5,90,20);
    lenumber->setInputMask("A999AA-99");

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()), dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(del_car()));
	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
}

void MainWindow::view_car_form()    //форма просмотра автомобилей
{
    QDialog *dialog = new QDialog;

    dialog->setGeometry(400,300,500,400);
    dialog->setWindowTitle(tr("View car"));
    dialog->show();

    treeWidget = new QTreeWidget(dialog);
    QStringList list;
    list << tr("Gos number") << tr("Mark") << tr("Color") << tr("Year") << tr("Available");

    treeWidget->setColumnCount(4);
    treeWidget->setHeaderLabels(list);

    treeWidget->setGeometry(0,0,500,400);
    treeWidget->show();
    view_car();
}

void MainWindow::search_car_form()  //форма поиска автомобиля
{
    QDialog *dialog = new QDialog(this);

    QLabel *lbnumber = new QLabel(tr("Number"),dialog);

    lenumber = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(200,200,200,200);
    dialog->setWindowTitle(tr("Search car"));

    lbnumber->setGeometry(5,25,90,20);

    lenumber->setGeometry(95,25,90,20);
    lenumber->setInputMask("A999AA-99");

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()),  dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(search_car()));
	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
}

void MainWindow::add_repair_form()   //форма добавления авто в ремонт
{
    QDialog *dialog = new QDialog;

    QLabel *lbnumber = new QLabel(tr("gos number"),dialog);

    lenumber = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(400,300,200,200);
	dialog->setWindowTitle(tr("Add car to repair"));

    lbnumber->setGeometry(5,5,90,20);

    lenumber->setGeometry(95,5,90,20);

    lenumber->setInputMask("A999AA-99");

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()), dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(add_repire_car()));
	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
}

void MainWindow::return_repair_form() //форма возврата авто из ремонта
{
    QDialog *dialog = new QDialog;

    QLabel *lbnumber = new QLabel(tr("gos number"),dialog);

    lenumber = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(400,300,200,200);
	dialog->setWindowTitle(tr("Car from repair"));

    lenumber->setInputMask("A999AA-99");

    lbnumber->setGeometry(5,5,90,20);

    lenumber->setGeometry(95,5,90,20);

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(return_from_repire()));
}

void MainWindow::car_to_client_form() //форма выдачи авто клиенту
{
    QDialog *dialog = new QDialog;

    QLabel *lbnumber = new QLabel(tr("gos number"),dialog);
	QLabel *lblicense = new QLabel(tr("rights"),dialog);
	QLabel *lbdelivery = new QLabel(tr("delivery date"),dialog);
	QLabel *lbreturn = new QLabel(tr("return date"),dialog);

    lenumber = new QLineEdit(dialog);
    lelicense_num = new QLineEdit(dialog);
    ledelivery = new QLineEdit(dialog);
	lereturn = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(400,300,200,200);
    dialog->setWindowTitle(tr("Car to client"));

    lelicense_num->setInputMask("99 AA 999999");
    lenumber->setInputMask("A999AA-99");
    ledelivery->setInputMask("0000-00-00");
	lereturn->setInputMask("0000-00-00");

    lbnumber->setGeometry(5,5,90,20);
    lblicense->setGeometry(5,25,90,20);
    lbdelivery->setGeometry(5,45,90,20);
	lbreturn->setGeometry(5,65,90,20);

    lenumber->setGeometry(95,5,90,20);
    lelicense_num->setGeometry(95,25,90,20);
    ledelivery->setGeometry(95,45,90,20);
	lereturn->setGeometry(95,65,90,20);

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()), dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(car_to_client()));
	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
}

void MainWindow::car_from_client_form()//форма возврата авто клиентом
{
    QDialog *dialog = new QDialog;

    QLabel *lbnumber = new QLabel(tr("gos number"),dialog);
	QLabel *lblicense_num = new QLabel(tr("rights"),dialog);

    lenumber = new QLineEdit(dialog);
    lelicense_num = new QLineEdit(dialog);

    QPushButton *ok = new QPushButton(tr("Ok"),dialog);
    QPushButton *cancel = new QPushButton(tr("Cancel"),dialog);

    dialog->setGeometry(400,300,200,200);
    dialog->setWindowTitle(tr("Car from client"));

    lelicense_num->setInputMask("99 AA 999999");
    lenumber->setInputMask("A999AA-99");

    lbnumber->setGeometry(5,5,90,20);
    lblicense_num->setGeometry(5,25,90,20);

    lenumber->setGeometry(95,5,90,20);
    lelicense_num->setGeometry(95,25,90,20);

    ok->setGeometry(50,170,50,30);
    cancel->setGeometry(100,170,50,30);

    dialog->show();

	dialog->connect(cancel, SIGNAL(clicked()),  dialog, SLOT(close()));
	dialog->connect(ok, SIGNAL(clicked()), this, SLOT(car_from_client()));
	dialog->connect(ok, SIGNAL(clicked()), dialog, SLOT(close()));
}

void MainWindow::show_hire_form()     //главная форма ремонта-выдачи
{
    hire_form = new QWidget;
    combohire = new QComboBox(hire_form);

    hire_form->show();
    hire_form->setGeometry(300,200,500,400);
    hire_form->setMaximumSize(300,300);
    hire_form->setWindowTitle(tr("Hire"));

    combohire->setGeometry(90,0,150,25);
	combohire->addItem(tr(""));
    combohire->addItem(tr("add to repair car"));
    combohire->addItem(tr("return form repair car"));
    combohire->addItem(tr("add car to client"));
    combohire->addItem(tr("return car from client"));
    combohire->addItem(tr("view hire"));

	connect(combohire, SIGNAL(currentIndexChanged(QString)), this, SLOT(change_combohire()));
}

void MainWindow::view_hire_form()
{
    QDialog *dialog = new QDialog;

	tableWidget = new QTableWidget(100,10,dialog);
    QStringList list;
	list << tr("Rights") << tr("Surname") << tr("Firstname") << tr("Middlename") << tr("Passport") << tr("Adress") << tr("Gos number") << tr("Delivery date") << tr("Return date") << tr("Costs");
    tableWidget->setHorizontalHeaderLabels(list);

	dialog->setGeometry(200,200,1050,400);
    dialog->setWindowTitle(tr("View Hire"));
    dialog->show();

	tableWidget->setGeometry(0,0,1050,400);
    tableWidget->show();

    int i=0;

    view_hire(this->client,this->hire,i);
}

void MainWindow::show_car_form()     //главная форма автомобилей
{
    car_form = new QWidget;
    combocar = new QComboBox(car_form);

    car_form->show();
    car_form->setGeometry(300,200,500,400);
    car_form->setMaximumSize(300,300);
    car_form->setWindowTitle(tr("car"));

    combocar->setGeometry(90,0,150,25);
	combocar->addItem(tr(""));
    combocar->addItem(tr("add car"));
    combocar->addItem(tr("remove car"));
    combocar->addItem(tr("view car"));
    combocar->addItem(tr("clear data"));
    combocar->addItem(tr("search car"));

	connect(combocar, SIGNAL(currentIndexChanged(QString)), this, SLOT(change_combocar()));
}

#endif // FORMS_H

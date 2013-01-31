#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "forms.h"
#include <QDate>

#include <QtGui>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	connect(ui->pushButton_client, SIGNAL(clicked()), this, SLOT(show_client_form()));
	connect(ui->pushButton_auto, SIGNAL(clicked()),  this, SLOT(show_car_form()));
	connect(ui->pushButton_hire, SIGNAL(clicked()),  this, SLOT(show_hire_form()));

    client=NULL;
    table = new Car *[100];
    hire=NULL;

    init_car_table();
}

bool MainWindow::add_to_tree(Client *client, int x1) //добавление в дерево
{
	Client *p = client;
    QString str;
    int x2;

    if(this->client==NULL)
    {
        this->client=new Client;
        this->client->license_number=lelicense_num->text();
        this->client->pasport_number=lepasport_num->text();
        this->client->surname=lesurname->text();
        this->client->firsname=lefirstname->text();
        this->client->middlename=lemiddlename->text();
        this->client->adress=leadr->text();
		this->client->useCount = 0;
        this->client->left=NULL;
        this->client->right=NULL;
        return true;
    }
    else
    {
        str=p->license_number;
        str.replace(0, 6, "");
        x2=str.toInt();

        if(x1 < x2)
        {
            if(p->left==NULL)
            {
                p->left=new Client;
                p->left->license_number=lelicense_num->text();
                p->left->pasport_number=lepasport_num->text();
                p->left->surname=lesurname->text();
                p->left->firsname=lefirstname->text();
                p->left->middlename=lemiddlename->text();
                p->left->adress=leadr->text();
				p->left->useCount = 0;
                p->left->left=NULL;
                p->left->right=NULL;
                return true;
            }
            else
                return add_to_tree(p->left, x1);
        }
        else
            if(p->right==NULL)
            {
                p->right=new Client;
                p->right->license_number=lelicense_num->text();
                p->right->pasport_number=lepasport_num->text();
                p->right->surname=lesurname->text();
                p->right->firsname=lefirstname->text();
                p->right->middlename=lemiddlename->text();
                p->right->adress=leadr->text();
				p->right->useCount = 0;
                p->right->left=NULL;
                p->right->right=NULL;
                return true;
            }
            else
                return add_to_tree(p->right, x1);
    }
}

void MainWindow::search_in_tree(Client *client, int &k) //поиск в дереве
{
    Client *p=client;

    if(p!=NULL)
    {
        if(p->license_number==lelicense_num->text())
            k=1;

        if(p->left!=NULL)
            search_in_tree(p->left,k);
        if(p->right!=NULL)
            search_in_tree(p->right,k);
    }
}

bool MainWindow::check_license_num(QString str)  //проверка маски лицензии
{
    const QRegExp rx("[0-9]{2}[\\ ][ABEKMHOPCTYX]{2}[\\ ][0-9]{6}");
    QRegExpValidator v(rx,this);
    int pos=0;

    if(v.validate(str, pos) == QValidator::Acceptable)
		return true;
	return false;
}

void MainWindow::add_client() //слот добавления клиента
{
    QString str=lelicense_num->text();
    QString number="";
    int x1=0;
    int k=0;

    if(check_license_num(str)==true)
    {
        number=str;
        number.replace(0, 6, "");

        x1=number.toInt();

        search_in_tree(this->client,k);

        if(k!=1)
        {
            if(add_to_tree(this->client, x1)==true)
            {
				QMessageBox::question(this, tr("Ok"), tr("Client is added"), QMessageBox::Ok, QMessageBox::Ok);

                if((check_heigth(this->client->right) - check_heigth(this->client->left)) == 2 &&
                        (check_heigth(this->client->right->left) <= check_heigth(this->client->right->right)))
                {
                    small_bal_left(this->client);
                }
                else
                    if((check_heigth(this->client->left) - check_heigth(this->client->right))==2 &&
                            (check_heigth(this->client->left->right) <= check_heigth(this->client->left->left)))
                    {
                        small_bal_right(this->client);
                    }
                    else
                        if((check_heigth(this->client->right) - check_heigth(this->client->left))==2 &&
                                (check_heigth(this->client->right->left) > check_heigth(this->client->right->right)))
                        {
                            big_bal_left(this->client);
                        }
                        else
                            if((check_heigth(this->client->left) - check_heigth(this->client->right))==2 &&
                                    (check_heigth(this->client->left->right) > check_heigth(this->client->left->left)))
                            {
                                big_bal_right(this->client);
                            }
            }
            else
            {
				QMessageBox::question(this, tr("Error"), tr("Client isn't' added"), QMessageBox::Ok,  QMessageBox::Ok);
            }
        }
        else
        {
			QMessageBox::question(this, tr("Error"), tr("Client already is"), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this, tr("Error"), tr("invalid rights"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void MainWindow::del_client() //слот удаления клиента
{
    QString str=lelicense_num->text();
    int k=0;

    if(check_license_num(str)==true)
    {
        search_in_tree(this->client, k);

        if(k==1)
        {
            if(del_from_tree(this->client))
            {
				QMessageBox::question(this, tr("Ok"), tr("Client is deleted"), QMessageBox::Ok, QMessageBox::Ok);

                if((check_heigth(this->client->right) - check_heigth(this->client->left)) == 2 &&
                        (check_heigth(this->client->right->left) <= check_heigth(this->client->right->right)))
                {
                    small_bal_left(this->client);
                }
                else
                    if((check_heigth(this->client->left) - check_heigth(this->client->right))==2 &&
                            (check_heigth(this->client->left->right) <= check_heigth(this->client->left->left)))
                    {
                        small_bal_right(this->client);
                    }
                    else
                        if((check_heigth(this->client->right) - check_heigth(this->client->left))==2 &&
                                (check_heigth(this->client->right->left) > check_heigth(this->client->right->right)))
                        {
                            big_bal_left(this->client);
                        }
                        else
                            if((check_heigth(this->client->left) - check_heigth(this->client->right))==2 &&
                                    (check_heigth(this->client->left->right) > check_heigth(this->client->left->left)))
                            {
                                big_bal_right(this->client);
                            }
            }
            else
            {
				QMessageBox::question(this, tr("Error"), tr("Client isn't deleted"), QMessageBox::Ok, QMessageBox::Ok);
            }
        }
        else
			QMessageBox::question(this, tr("Error"), tr("Client isn't exists"), QMessageBox::Ok, QMessageBox::Ok);
    }
    else
    {
		QMessageBox::question(this, tr("Error"), tr("invalid rights"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void MainWindow::clear_data_clients(Client *client) //удаление данных клиентов
{
    if(client!=NULL)
    {
        clear_data_clients(client->left);
        clear_data_clients(client->right);
        delete client;
        this->client = NULL;
    }
}

int MainWindow::check_heigth(Client *client) //вычисление высоты дерева для балансировки
{
    Client *p=client;
    int h1,h2;

    if(p!=NULL)
    {
        h1=check_heigth(p->left);
        h2=check_heigth(p->right);

        if(h1>h2)
            return 1+h1;
        else
            return 1+h2;
    }
}

void MainWindow::small_bal_left(Client *client) //малая левая балансировка
{
    Client *p=client;
    Client *tmp=client->right;

    p=tmp;
    client->right=tmp->left;
    p->left=client;
    this->client=p;
}

void MainWindow::small_bal_right(Client *client) //малая правая балансировка
{
    Client *p=client;
    Client *tmp=client->left;

    p=tmp;
    client->left=tmp->right;
    p->right=client;
    this->client=p;
}

void MainWindow::big_bal_left(Client *client) //большая левая балансировка
{
    Client *p1=client;
    Client *p2=client->right;
    Client *p3=client->right->left;

    p1->right=p3->left;
    p2->left=p3->right;
    p3->left=p1;
    p3->right=p2;
    this->client=p3;
}

void MainWindow::big_bal_right(Client *client) //большая правая балансировка
{
    Client *p1=client;
    Client *p2=client->left;
    Client *p3=client->left->right;

    p1->left=p3->right;
    p2->right=p3->left;
    p3->right=p1;
    p3->left=p2;
    this->client=p3;
}

bool MainWindow::del_from_tree(Client *client) //удаление из дерева
{
    Client *p=client;
    Client *p1;

    if(p!=NULL)
    {
        if(p->license_number==lelicense_num->text())
        {
            if(p->left==NULL && p->right==NULL)
            {
                delete this->client;
                this->client=NULL;
                return true;
            }
            else
            {
                if(p->left!=NULL && p->right==NULL)
                {
                    p=p->left;
                    delete this->client;
                    this->client=p;
                    return true;
                }
                else
                    if(p->right!=NULL && p->left==NULL)
                    {
                        p=p->right;
                        delete this->client;
                        this->client=p;
                        return true;
                    }
                    else
                        if(p->left!=NULL && p->right!=NULL)
                        {
                            p1=p->left;
                            while(p1->right!=NULL)
                                p1=p1->right;
                            p1->right=p->right;
                            delete this->client;
                            this->client=p1;
                            p1=NULL;
                        }
            }
        }
        if(p->left!=NULL && p->left->license_number==lelicense_num->text())
        {
            if(p->left->left==NULL && p->left->right==NULL)
            {
                delete p->left;
                p->left=NULL;
                return true;
            }
            else
            {
                if(p->left->left!=NULL && p->left->right==NULL)
                {
                    p1=p->left->left;
                    delete p->left;
                    p->left=p1;
                    p1=NULL;
                    return true;
                }
                else
                    if(p->left->right!=NULL && p->left->left==NULL)
                    {
                        p1=p->left->right;
                        delete p->left;
                        p->left=p1;
                        return true;
                    }
                    else
                        if(p->left->left!=NULL && p->left->right!=NULL)
                        {
                            p1=p->left->left;
                            while(p1->right!=NULL)
                                p1=p1->right;
                            p1->right=p->left->right;
                            delete p->left;
                            p->left=p1;
                            p1=NULL;
                        }
            }
        }
        if(p->right!=NULL && p->right->license_number==lelicense_num->text())
        {
            if(p->right->left==NULL && p->right->right==NULL)
            {
                delete p->right;
                p->right=NULL;
                return true;
            }
            else
            {
                if(p->right->left!=NULL && p->right->right==NULL)
                {
                    p1=p->right->left;
                    delete p->right;
                    p->right=p1;
                    return true;
                }
                else
                    if(p->right->right!=NULL && p->right->left==NULL)
                    {
                        p1=p->right->right;
                        delete p->right;
                        p->right=p1;
                        return true;
                    }
                    else
                        if(p->right->left!=NULL && p->right->right!=NULL)
                        {
                            p1=p->right->left;
                            while(p1->right!=NULL)
                                p1=p1->right;
                            p1->right=p->right->right;
                            delete p->right;
                            p->right=p1;
                            p1=NULL;
                        }
            }
        }

        del_from_tree(p->left);
        del_from_tree(p->right);
    }
}

void MainWindow::search_client() //поиск клиента
{
    QString str=lelicense_num->text();
    int k=0;

    if(check_license_num(str)==true)
    {
        search_in_tree(this->client,k);

        if(k==1)
        {
			QMessageBox::question(this, tr("Ok"), tr("Client is exists"), QMessageBox::Ok, QMessageBox::Ok);
        }
        else
        {
			QMessageBox::question(this, tr("Ok"), tr("Client isn't exists"), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this, tr("Error"), tr("invalid rights"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void MainWindow::view_client(Client *client, int &i) //просмотр клиентов
{
    Client *p=client;

    if(p!=NULL)
    {
        view_client(p->right,i);

        QTableWidgetItem *tableItem1 = new QTableWidgetItem;
        tableItem1->setText(p->license_number);
        tableWidget->setItem(i,0,tableItem1);
        QTableWidgetItem *tableItem2 = new QTableWidgetItem;
        tableItem2->setText(p->surname);
        tableWidget->setItem(i,1,tableItem2);
        QTableWidgetItem *tableItem3 = new QTableWidgetItem;
        tableItem3->setText(p->firsname);
        tableWidget->setItem(i,2,tableItem3);
        QTableWidgetItem *tableItem4 = new QTableWidgetItem;
        tableItem4->setText(p->middlename);
        tableWidget->setItem(i,3,tableItem4);
        QTableWidgetItem *tableItem5 = new QTableWidgetItem;
        tableItem5->setText(p->pasport_number);
        tableWidget->setItem(i,4,tableItem5);
        QTableWidgetItem *tableItem6 = new QTableWidgetItem;
        tableItem6->setText(p->adress);
        tableWidget->setItem(i,5,tableItem6);
		QTableWidgetItem *tableItem7 = new QTableWidgetItem;
		tableItem7->setText(QString().setNum(p->useCount));
		tableWidget->setItem(i,6,tableItem7);

        ++i;

        view_client(p->left,i);
    }
}

void MainWindow::change_comboclient() //обработчик ComboBox клиента
{
    if(comboclient->currentText() == "registration client")
        add_client_form();

    if(comboclient->currentText() == "remove client")
        remove_client_form();

    if(comboclient->currentText() == "view clients")
        view_client_form();

    if(comboclient->currentText() == "clear data")
        clear_data_clients(client);

    if(comboclient->currentText() == "search client")
        search_client_form();
}

void MainWindow::search_client_for(Client *client, int &i)
{
    QString surname=lesurname->text();
    QString firstname=lefirstname->text();
    QString middlename=lemiddlename->text();
    QString license=lelicense_num->text();

    if(license.size()==12 && !check_license_num(license))
    {
			QMessageBox::question(this,  tr("Error"),tr("invalid rights"), QMessageBox::Ok, QMessageBox::Ok);
    }
    else
    {
        Client *pc=client;
        Hire *ph=hire;

        if(pc!=NULL)
        {
            search_client_for(pc->right,i);

            if(surname.size()>0 && pc->surname==surname || firstname.size()>0 && pc->firsname==firstname ||
               middlename.size()>0 && pc->middlename==middlename || license.size()>0 && pc->license_number==license)
            {
                QTableWidgetItem *tableItem1 = new QTableWidgetItem;
                tableItem1->setText(pc->license_number);
                tableWidget->setItem(i,0,tableItem1);
                QTableWidgetItem *tableItem2 = new QTableWidgetItem;
                tableItem2->setText(pc->surname);
                tableWidget->setItem(i,1,tableItem2);
                QTableWidgetItem *tableItem3 = new QTableWidgetItem;
                tableItem3->setText(pc->firsname);
                tableWidget->setItem(i,2,tableItem3);
                QTableWidgetItem *tableItem4 = new QTableWidgetItem;
                tableItem4->setText(pc->middlename);
                tableWidget->setItem(i,3,tableItem4);
                QTableWidgetItem *tableItem5 = new QTableWidgetItem;
                tableItem5->setText(pc->pasport_number);
                tableWidget->setItem(i,4,tableItem5);
                QTableWidgetItem *tableItem6 = new QTableWidgetItem;
                tableItem6->setText(pc->adress);
                tableWidget->setItem(i,5,tableItem6);

                if(check_hire_client(pc))
                {
                    while(ph!=NULL)
                    {
                        if(ph->license_number==pc->license_number)
                        {
                            QTableWidgetItem *tableItem6 = new QTableWidgetItem;
                            tableItem6->setText(ph->gos_number);
                            tableWidget->setItem(i,6,tableItem6);
                            break;
                        }
                        else
                            ph=ph->next;
                    }
                }

                ++i;
            }

            search_client_for(pc->left,i);
        }
    }
}

bool MainWindow::search_client_for_hire(Client *client, Hire *hire, int &i)
{
    if(client!=NULL)
    {
        search_client_for_hire(client->right, hire, i);

        if(client->license_number==hire->license_number)
        {
            QTableWidgetItem *tableItem1 = new QTableWidgetItem;
            tableItem1->setText(client->license_number);
            tableWidget->setItem(i,0,tableItem1);
            QTableWidgetItem *tableItem2 = new QTableWidgetItem;
            tableItem2->setText(client->surname);
            tableWidget->setItem(i,1,tableItem2);
            QTableWidgetItem *tableItem3 = new QTableWidgetItem;
            tableItem3->setText(client->firsname);
            tableWidget->setItem(i,2,tableItem3);
            QTableWidgetItem *tableItem4 = new QTableWidgetItem;
            tableItem4->setText(client->middlename);
            tableWidget->setItem(i,3,tableItem4);
            QTableWidgetItem *tableItem5 = new QTableWidgetItem;
            tableItem5->setText(client->pasport_number);
            tableWidget->setItem(i,4,tableItem5);
            QTableWidgetItem *tableItem6 = new QTableWidgetItem;
            tableItem6->setText(client->adress);
            tableWidget->setItem(i,5,tableItem6);

            if(check_hire_client(client))
            {
                while(hire!=NULL)
                {
                    if(hire->license_number==client->license_number)
                    {
                        QTableWidgetItem *tableItem6 = new QTableWidgetItem;
                        tableItem6->setText(hire->gos_number);
                        tableWidget->setItem(i,6,tableItem6);
                        break;
                    }
                    else
                        hire=hire->next;
                }
            }
        }
        ++i;

        return true;

        search_client_for_hire(client->left, hire, i);
    }
}




void MainWindow::init_car_table() //инициализация таблицы
{
    for(int i=0;i<100;++i)
    {
        table[i]=new Car;
        table[i]=NULL;
    }
}

int MainWindow::hash() //хеш-функция
{
    int h=0;
    int k=0;
    QString s=lenumber->text();
    char c[3];
    c[0]=s.toAscii().data()[0];
    c[1]=s.toAscii().data()[4];
    c[2]=s.toAscii().data()[5];
    s.replace(4,7,"");

    for(int i=1;i<4;++i)
    {
        s.replace(0,1,"");
        k=s.toInt();
        h+=k*k*c[i-1];
    }
    h%=100;

    return h;
}

bool MainWindow::check_number(QString str) //проверка номера
{
    const QRegExp rx1("[ABEKMHOPCTYX]{1}[0-9]{3}[ABEKMHOPCTYX]{2}[\\-][0-9]{2}");
    QRegExpValidator v1(rx1,this);
    int pos=0;

    if(v1.validate(str, pos) == QValidator::Acceptable)
		return true;
	return false;
}

bool MainWindow::check_key(Car *p) //помощник в поиске авто
{
    QString key1=lenumber->text();
    QString key2=p->gos_number;

    if(key1!=key2)
    {
		return false;
    }
	return true;
}

bool MainWindow::add_in_table() //добавление элемента в таблицу
{
    int h=0;
    Car *p;

    h=hash();

    if(table[h]==NULL)
        {
            table[h]=new Car;
            table[h]->gos_number=lenumber->text();
            table[h]->mark=lemark->text();
            table[h]->color=lecolor->text();
            table[h]->year=leyear->text();
            table[h]->available=true;
            table[h]->next=new Car;
            table[h]->next=NULL;
            return true;
        }
        else
        {
            p=table[h];

            while(p->next!=NULL)
                p=p->next;

            p->next=new Car;
            p->next->gos_number=lenumber->text();
            p->next->mark=lemark->text();
            p->next->color=lecolor->text();
            p->next->year=leyear->text();
            p->next->available=true;
            p->next->next=NULL;
            return true;
        }
    return false;
}

void MainWindow::add_car() //слот добавления авто
{
    QString str=lenumber->text();

    if(check_number(str)==true)
    {
        if(search_in_table()==false)
        {
            if(add_in_table())
            {
				QMessageBox::question(this,tr("Ok"), tr("Car is added"),QMessageBox::Ok,  QMessageBox::Ok);
            }
            else
            {
				QMessageBox::question(this, tr("Error"),tr("Car isn't added"),QMessageBox::Ok, QMessageBox::Ok);
            }
        }
        else
        {
			QMessageBox::question(this,tr("Error"),tr("Car is exists"),QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this,tr("Error"), tr("Invalid number"), QMessageBox::Ok, QMessageBox::Ok);
    }

    lenumber->clear();
}

void MainWindow::del_car() //слот удаления автомобиля
{
    QString str=lenumber->text();

    if(check_number(str)==true)
    {
        Car *p;
        int h;

        h=hash();
        p=table[h];

        if(!check_hire_car(p))
        {
            if(search_in_table())
            {
                if(del_from_table())
                {
					QMessageBox::question(this, tr("Ok"), tr("Car is deleted"),  QMessageBox::Ok, QMessageBox::Ok);
                }
                else
                {
					QMessageBox::question(this, tr("Ok"),tr("Car isn't deleted"),  QMessageBox::Ok, QMessageBox::Ok);
                }
            }
            else
            {
				QMessageBox::question(this,tr("Ok"), tr("Car isn't exist"),QMessageBox::Ok,QMessageBox::Ok);
            }
        }
        else
        {
			QMessageBox::question(this, tr("Error"),tr("Car at the client"), QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this, tr("Error"), tr("Invalid number"),QMessageBox::Ok, QMessageBox::Ok);
    }

    lenumber->clear();
}

void MainWindow::search_car() //слот поиска авто
{
    QString str=lenumber->text();

    if(check_number(str)==true)
    {
        if(search_in_table())
        {
			QMessageBox::question(this, tr("Ok"), tr("Car is exists"), QMessageBox::Ok, QMessageBox::Ok);
        }
        else
        {
			QMessageBox::question(this, tr("Error"), tr("Car isn't exists"), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this, tr("Error"), tr("Invalid number"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

bool MainWindow::search_in_table() //поиск в таблице
{
    Car *p;
    bool b;
	int h=hash();

    p=table[h];
    while (p!= NULL)
    {
        if (check_key(p) == false)
        {
            p = p->next;
            b = false;
        }
        else
		{
            return true;
        }
    }

	if(!b)
        return false;
}

bool MainWindow::del_from_table() //удаление из таблицы
{
    Car *p,*tmp;
    bool b=false;
	int h=hash();
    p=table[h];

    if(check_key(p)==true)
    {
        if(table[h]->next==NULL)
        {
            delete table[h];
            table[h]=NULL;
        }
        else
        {
            p=table[h]->next;
            delete table[h];
            table[h]=p;
        }
        b=true;
    }
    else
    {
        p=table[h];
        while (!check_key(p->next))
        {
            tmp=p->next;
            p=p->next;
        }

        tmp=p->next->next;
        delete p->next;
        p->next=NULL;
        p->next=tmp;
        b = true;
    }
	return b;
}

void MainWindow::clear_data_car() //очистка данных авто
{
	Car *p;

    for(int i=0;i<100;++i)
    {
        if(table[i]!=NULL)
        {
            p=table[i];
            if(p->next==NULL)
            {
                delete table[i];
                table[i]=NULL;
            }
            else
            {
                while(p->next!=NULL)
                {
                    p=table[i];
                    delete table[i];
                    table[i]=NULL;
                    table[i]=p->next;
                }
            }
        }
    }
}

void MainWindow::view_car() //просмотр автомобиля
{
    Car *p;

    QList<QTreeWidgetItem *> items;

    QStringList col;
    QTreeWidgetItem *item;
    QTreeWidgetItem *child;

    for(int i=0;i<100;++i)
    {
        if(table[i]!=NULL)
        {
            col.clear();

            col << table[i]->gos_number << table[i]->mark << table[i]->color << table[i]->year;
            if(table[i]->available==true)
                col << "true";
            else
                col << "false";

            item = new QTreeWidgetItem(col);

            if(table[i]->next!=NULL)
            {
                p=table[i];
                while(p->next!=NULL)
                {
                    col.clear();

                    col << p->next->gos_number << p->next->mark << p->next->color << p->next->year;
                    if(p->next->available==true)
                        col << "true";
                    else
                        col << "false";

                    child = new QTreeWidgetItem(col);
                    item->addChild(child);

                    p=p->next;
                }
            }
        }

        items.append(item);
        treeWidget->insertTopLevelItems(0,items);
    }
}

void MainWindow::change_combocar()   //обработчик ComboBox автомобиля
{
    if(combocar->currentText() == "add car")
        add_car_form();

    if(combocar->currentText() == "remove car")
        remove_car_form();

    if(combocar->currentText() == "view car")
        view_car_form();

    if(combocar->currentText() == "clear data")
        clear_data_car();

    if(combocar->currentText() == "search car")
        search_car_form();
}



bool MainWindow::check_hire_client(Client *client)
{
    Hire *ph;
    Client *pc;

    pc=client;
    ph=hire;

    while(ph!=NULL)
    {
        if(ph->license_number==pc->license_number)
            return true;
        else
            ph=ph->next;
    }
    return false;
}

bool MainWindow::check_hire_car(Car *p)
{
    Hire *ph;
    ph=hire;

    while(ph!=NULL)
    {
        if(ph->gos_number==p->gos_number)
            return true;
        else
            ph=ph->next;
    }
    return false;
}

void MainWindow::add_repire_car() //слот добавления авто в ремонт
{
    QString str=lenumber->text();

    if(check_number(str)==true)
    {
        Car *p;
        int h;

        h=hash();
        p=table[h];

        if(!check_hire_car(p))
        {
            if(search_in_table())
            {
                while(!check_key(p))
                    p=p->next;

                if(p->available)
                    p->available=false;
                else
                {
					QMessageBox::question(this,tr("Error"), tr("car in the repair"),QMessageBox::Ok, QMessageBox::Ok);
                }
            }
            else
            {
				QMessageBox::question(this,tr("Error"),tr("Car isn't exists"),QMessageBox::Ok, QMessageBox::Ok);
            }
        }
        else
        {
			QMessageBox::question(this, tr("Error"), tr("Car at the client"), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this, tr("Error"), tr("Invalid number"),QMessageBox::Ok,QMessageBox::Ok);
    }
}

void MainWindow::return_from_repire() //слот возврата с ремонта
{
    QString str=lenumber->text();

    if(check_number(str)==true)
    {
        if(search_in_table())
        {
            Car *p;
            int h;

            h=hash();
            p=table[h];

            while(!check_key(p))
                p=p->next;

            if(!p->available)
                p->available=true;
            else
            {
				QMessageBox::question(this,tr("Error"),tr("car does not in the repair"),QMessageBox::Ok, QMessageBox::Ok);
            }
        }
        else
        {
			QMessageBox::question(this, tr("Error"), tr("Car isn't exists"), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this, tr("Error"),  tr("Invalid number"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void MainWindow::car_to_client() //слот передачи авто клиенту
{
    QString license=lelicense_num->text();
    QString number=lenumber->text();
    QString str;
    QString str2;
    int h, x1, x2;
    Hire *p;
    Car *pcar;
    Client *pclient=client;
    h=hash();
    pcar=table[h];
    p=hire;

    str2=license;
    str2.replace(0, 6, "");
    x1=str2.toInt();

    while(pcar!=NULL && !check_key(pcar))
        pcar=pcar->next;

    while(pclient!=NULL)
    {
        str=pclient->license_number;
        str.replace(0, 6, "");
        x2=str.toInt();

        if(pclient->license_number==license)
            break;

        if(x1 < x2)
        {
            pclient=pclient->left;
        }
        else
            pclient=pclient->right;
    }


    if(pcar==NULL)
    {
		QMessageBox::question(this, tr("Error"),tr("Car isn't exist"),  QMessageBox::Ok, QMessageBox::Ok);
    }
    else
        if(pclient==NULL)
        {
			QMessageBox::question(this, tr("Error"), tr("Client isn't exist"), QMessageBox::Ok, QMessageBox::Ok);
        }
        else
        {
            if(check_license_num(license))
            {
                if(check_number(number))
                {
                    if(check_hire_car(pcar) || pcar->available==false)
                    {
						QMessageBox::question(this, tr("Error"),tr("Car is busy"), QMessageBox::Ok, QMessageBox::Ok);
                    }
                    else
                        if(check_hire_client(pclient))
                        {
							QMessageBox::question(this, tr("Error"), tr("Client has already took the car"), QMessageBox::Ok, QMessageBox::Ok);
                        }
					else
						if (!QDate::fromString(ledelivery->text(), "yyyy-MM-dd").isValid() || !QDate::fromString(lereturn->text(), "yyyy-MM-dd").isValid())
						{
							QMessageBox::question(this, tr("Error"), tr("Error. Invalid date."), QMessageBox::Ok, QMessageBox::Ok);
						}
					else
						if (ledelivery->text() >= lereturn->text() || ledelivery->text() < QDate::currentDate().toString("yyyy-MM-dd") )
						{
							QMessageBox::question(this, tr("Error"), tr("Date error"), QMessageBox::Ok, QMessageBox::Ok);
						}
                        else
                        {
                            if(hire==NULL)
                            {
                                this->hire=new Hire;
                                this->hire->license_number=lelicense_num->text();
                                this->hire->gos_number=lenumber->text();
								this->hire->delivery_date=ledelivery->text();
								this->hire->return_date=lereturn->text();
								pclient->useCount++;
                                this->hire->next=NULL;

                                pcar->available=false;

								QMessageBox::question(this, tr("Ok"), tr("Client took the car"), QMessageBox::Ok, QMessageBox::Ok);
                            }
                            else
                            {
                                p=hire;
                                while(p->next!=NULL)
                                    p=p->next;
                                p->next=new Hire;
                                p->next->license_number=lelicense_num->text();
                                p->next->gos_number=lenumber->text();
								p->next->delivery_date= ledelivery->text();
								p->next->return_date= lereturn->text();
								pclient->useCount++;
                                p->next->next=NULL;

                                pcar->available=false;

								QMessageBox::question(this, tr("Ok"), tr("Client took the car"),QMessageBox::Ok, QMessageBox::Ok);
                            }
                        }
                }
                else
                {
					QMessageBox::question(this, tr("Error"), tr("Invalid number"), QMessageBox::Ok, QMessageBox::Ok);
                }
            }
            else
            {
				QMessageBox::question(this, tr("Error"), tr("Invalid rights"), QMessageBox::Ok, QMessageBox::Ok);
            }
        }
}

void MainWindow::car_from_client()
{
    QString license=lelicense_num->text();
    QString number=lenumber->text();
    QString str, str2;
    int h, x2, x1;
    Hire *p, *p1;
    Car *pcar;
    Client *pclient;

    str2=number;
    str2.replace(0, 6, "");
    x1=str.toInt();

    h=hash();
    pcar=table[h];
    p=hire;
    pclient=client;

    while(!check_key(pcar))
        pcar=pcar->next;

    while(pclient!=NULL)
    {
        str=pclient->license_number;
        str.replace(0, 6, "");
        x2=str.toInt();

        if(pclient->license_number==license)
            break;

        if(x1 < x2)
        {
            pclient=pclient->left;
        }
        else
            pclient=pclient->right;
    }


    if(check_license_num(license))
    {
        if(check_number(number))
        {
            if(check_hire_car(pcar) && check_hire_client(pclient))
            {
                while(p->license_number!=pclient->license_number && p->gos_number!=pcar->gos_number)
                {
                    p1=p;
                    p=p->next;
                }

                if(p->next==NULL)
                {
                    p1=p->next;
                    delete p;
                    p=new Hire;
                    p=NULL;
                    p=p1;

                    pcar->available=true;

					QMessageBox::question(this, tr("Ok"), tr("Client gave the car"), QMessageBox::Ok, QMessageBox::Ok);
                }
                else
                {
                    p1=p->next;
                    delete p;
                    p=NULL;
                    p=new Hire;
                    p=p1;

                    pcar->available=true;

					QMessageBox::question(this, tr("Ok"), tr("Client gave the car"), QMessageBox::Ok, QMessageBox::Ok);
                }
            }
            else
            {
				QMessageBox::question(this, tr("Error"), tr("Can't find transaction"), QMessageBox::Ok, QMessageBox::Ok);
            }
        }
        else
        {
			QMessageBox::question(this, tr("Error"), tr("Invalid number"), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else
    {
		QMessageBox::question(this, tr("Error"), tr("Invalid rights"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void MainWindow::view_hire(Client *client, Hire *hire, int &i)
{
    Client *pc=client;
    Hire *ph=hire;

    if(pc!=NULL)
    {
        view_hire(pc->right,this->hire,i);

        if(check_hire_client(pc))
        {
            while(ph!=NULL)
            {
                if(ph->license_number==pc->license_number)
                {
                    QTableWidgetItem *tableItem1 = new QTableWidgetItem;
                    tableItem1->setText(pc->license_number);
                    tableWidget->setItem(i,0,tableItem1);
                    QTableWidgetItem *tableItem2 = new QTableWidgetItem;
                    tableItem2->setText(pc->surname);
                    tableWidget->setItem(i,1,tableItem2);
                    QTableWidgetItem *tableItem3 = new QTableWidgetItem;
                    tableItem3->setText(pc->firsname);
                    tableWidget->setItem(i,2,tableItem3);
                    QTableWidgetItem *tableItem4 = new QTableWidgetItem;
                    tableItem4->setText(pc->middlename);
                    tableWidget->setItem(i,3,tableItem4);
                    QTableWidgetItem *tableItem5 = new QTableWidgetItem;
                    tableItem5->setText(pc->pasport_number);
                    tableWidget->setItem(i,4,tableItem5);
                    QTableWidgetItem *tableItem6 = new QTableWidgetItem;
                    tableItem6->setText(pc->adress);
                    tableWidget->setItem(i,5,tableItem6);
                    QTableWidgetItem *tableItem7 = new QTableWidgetItem;
                    tableItem7->setText(ph->gos_number);
                    tableWidget->setItem(i,6,tableItem7);
                    QTableWidgetItem *tableItem8 = new QTableWidgetItem;
					tableItem8->setText(ph->delivery_date);
                    tableWidget->setItem(i,7,tableItem8);
                    QTableWidgetItem *tableItem9 = new QTableWidgetItem;
					tableItem9->setText(ph->return_date);
					tableWidget->setItem(i,8,tableItem9);
					QTableWidgetItem *tableItem10 = new QTableWidgetItem;
					int useDays = QDate::fromString(ph->delivery_date, "yyyy-MM-dd").daysTo(QDate::fromString(ph->return_date, "yyyy-MM-dd"));
					int costs = useDays > 3 ? 3000 + (useDays - 3) * 500 : costs = useDays * 1000;
					int minusHundred = pc->useCount / 3;
					minusHundred = minusHundred > 5 ? minusHundred = 500 : minusHundred * 100;
					tableItem10->setText(QString().setNum(costs - minusHundred));
					tableWidget->setItem(i,9,tableItem10);
                    ++i;
                    break;
                }
                else
                    ph=ph->next;
            }
        }

        view_hire(pc->left,this->hire,i);
    }
}


void MainWindow::change_combohire()   //обработчик ComboBox ремонта
{
    if(combohire->currentText() == "add to repair car")
        add_repair_form();

    if(combohire->currentText() == "return form repair car")
        return_repair_form();

    if(combohire->currentText() == "add car to client")
        car_to_client_form();

    if(combohire->currentText() == "return car from client")
        car_from_client_form();

	if(combohire->currentText() == "view hire")
        view_hire_form();
}

MainWindow::~MainWindow()
{
    delete ui;
}

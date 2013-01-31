#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDate>
#include <QtGui>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    struct Client
    {
        QString license_number;
        QString surname;
        QString firsname;
        QString middlename;
        QString pasport_number;
        QString adress;
		int useCount;

        Client *right;
        Client *left;
    };

    struct Car
    {
        QString gos_number;
        QString mark;
        QString color;
        QString year;
        bool available;

        Car *next;
    };

    struct Hire
    {
        QString license_number;
        QString gos_number;
		QString delivery_date;
		QString return_date;

        Hire *next;
    };

    Client *client;
    Car **table;
    Hire *hire;

    QWidget *client_form;
    QComboBox *comboclient;

    QWidget *car_form;
    QComboBox *combocar;

    QWidget *hire_form;
    QComboBox *combohire;

    QLineEdit *lelicense_num;
    QLineEdit *lesurname;
    QLineEdit *lefirstname;
    QLineEdit *lemiddlename;
    QLineEdit *lepasport_num;
    QLineEdit *leadr;

    QLineEdit *lenumber;
    QLineEdit *lemark;
    QLineEdit *lecolor;
    QLineEdit *leyear;

	QLineEdit *ledelivery;
	QLineEdit *lereturn;

    QTableWidget *tableWidget;
    QTreeWidget  *treeWidget;

    Ui::MainWindow *ui;

public:
    void add_client_form();
    void remove_client_form();
    void view_client_form();
    bool add_to_tree(Client *client, int x1);
    void search_in_tree(Client *client, int &k);
    void search_in_tree_for(Client *client);
    void view_client(Client *client, int &i);
    bool del_from_tree(Client *client);
    void search_client_form();
    void search_client_for(Client *client, int &i);
    bool search_client_for_hire(Client *client, Hire *hire, int &i);
    void clear_data_clients(Client *client);
    int  check_heigth(Client *client);
    void small_bal_left(Client *client);
    void small_bal_right(Client *client);
    void big_bal_left(Client *client);
    void big_bal_right(Client *client);
    bool check_license_num(QString str);

    void add_car_form();
    void remove_car_form();
    void view_car_form();
    void search_car_form();
    void init_car_table();
    int  hash();
    bool check_key(Car *p);
    bool search_in_table();
    bool add_in_table();
    bool del_from_table();
    void view_car();
    void clear_data_car();
    bool check_number(QString str);

    void add_repair_form();
    void return_repair_form();
    void car_to_client_form();
    void car_from_client_form();
    bool check_hire_client(Client *client);
    bool check_hire_car(Car *p);
    void view_hire(Client *client, Hire *hire, int &i);
    void view_hire_form();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void show_client_form();
    void show_car_form();
    void show_hire_form();

    void add_client();
    void del_client();
    void search_client();
    void search_client_for_form();

    void add_car();
    void del_car();
    void search_car();

    void add_repire_car();
    void return_from_repire();
    void car_to_client();
    void car_from_client();

    void change_comboclient();
    void change_combocar();
    void change_combohire();
};

#endif // MAINWINDOW_H

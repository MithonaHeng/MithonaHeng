#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>


using namespace std;

void showSQLError(unsigned int handleType, const SQLHANDLE& handle) {

    SQLCHAR SQLState[1024];
    SQLCHAR message[1024];
    if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
        cout << "SQL Driver Message: " << message << "\nSQL State: " << SQLState << "." << endl;

}

int main()
{
    SQLHANDLE SQLEnvHandle = NULL;
    SQLHANDLE SQLConnectionHandle = NULL;
    SQLHANDLE SQLstatementHandle = NULL;
    SQLRETURN retCode = 0;
    char SQLQuery[] = "SELECT * FROM departments";

    do {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
            break;
        if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
            break;
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
            break;
        if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
            break;
        SQLCHAR retConString[1024];

        //connection Driver and open connection

        switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=localhost; 1433; DATABASE=HRDB; UID=demoID; PWD=demo123;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
        case SQL_SUCCESS:
            break;
        case SQL_SUCCESS_WITH_INFO:
            break;
        case SQL_NO_DATA_FOUND:
            showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
            retCode = -1;
            break;
        case SQL_INVALID_HANDLE:
            showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
            retCode = -1;
            break;
        case SQL_ERROR:
            showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
            retCode = -1;
            break;
        default:
            break;

        }
        if (retCode == -1)
            break;
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLstatementHandle))
            break;
        


    // Working process start from here
        //This is the code where SQL are used
         
        if (SQL_SUCCESS != SQLExecDirect(SQLstatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
            showSQLError(SQL_HANDLE_STMT, SQLstatementHandle);
            break;
        }
        else {
            char name[250];
            int id;
            int location;
            while (SQLFetch(SQLstatementHandle) == SQL_SUCCESS) {
                SQLGetData(SQLstatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
                SQLGetData(SQLstatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);
                SQLGetData(SQLstatementHandle, 3, SQL_C_DEFAULT, &location, sizeof(location), NULL);
                cout << id << " " << name << " " << location << endl;
            }
        }
    // end here
    } while (FALSE);
    SQLFreeHandle(SQL_HANDLE_STMT, SQLstatementHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

    std::cout << "\nEnd of the code!\n";
}


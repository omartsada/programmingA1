#include <cstddef>
#include <string>
#include <iostream>
#include "version.cpp"
using namespace std;

int main(int myInt, char* myChar[])
{
displayversion();
    string url = "https://cs.utdallas.edu:80/directory/faculty/people.html?name=Robert";
    string foundedProtocols[] = { "http", "https", "ftp", "ftps" };
    int x = 0;
    string protocol = url.substr(0, url.find("://"));
   
    size_t get = url.find(":");
    protocol = url.substr(0, get);
    for (int i = 0; i < 5; i++) {


            if (protocol == foundedProtocols[i]) {
             
                break;

            }
            if (i == 4) {
                cout << protocol << " is not a valid protocol" << endl;
                return 1;
            }
        }
    string url_new = url.substr(get + 3);
    size_t x1 = url_new.find(":");
    string domain = url_new.substr(0, x1);

    size_t x2 = url_new.find("/");
    string port = url_new.substr(x1 + 1, x2 - x1 - 1);
    string path = url_new.substr(url_new.find_first_of("/"));
    path = path.substr(0, path.find_last_of("?"));
    size_t x3 = url_new.find("?") + 1;
    string parameters = url_new.substr(x3);

    cout << "Protocol  " << protocol << endl;
    cout << "Domain  " << domain << endl;
    cout << "Port  " << port << endl;
    cout << "Path  " << path << endl;
    cout << "parameters   "<<parameters << endl;

    return -1;
   

    string followingProtocol = url.substr(url.find("://") + 3);
    domain = followingProtocol.substr(0, followingProtocol.find("/"));
    cout << domain.substr(domain.find(":") + 1) << endl;
     port = stoi(domain.substr(domain.find(":") + 1));
    int port1 = 0;
    try {
       
        port1 = stoi(port);

        if (port1 < 1 || port1 > 65535)
        {
            cout << "Port number must be between 1 and 65535" << endl;
        }


        cout << "Port: " << port << endl;
       
    }
    catch (std::invalid_argument const& ex) {
       
        cout << "The port is invalid.\n";
    }

    domain = domain.substr(0, domain.find(":"));
    cout << "Domain: " << domain << endl;
    cout << "Port: " << port1 << endl;

   
    string followingDomain = followingProtocol.substr(followingProtocol.find("/") + 1);
   
    string filePath = followingDomain.substr(0, followingDomain.find("?"));
    cout << "File Path: " << filePath << endl;

   
     parameters = followingDomain.substr(followingDomain.find("?") + 1);
    cout << "Parameters: " << parameters << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include <direct.h>
#include<windows.h>
using namespace std;
struct file
{
	string name;
	char * content;
	string extention;
	long  size;
	file() {
		size = 0;
	}

}; 
struct folder
{
	string name;
	vector <file>files_in_this_folder;
};
struct part
{
	string name;
	vector<folder>folders;
	vector<file>files;
};
int main()
{
	
	part MyDisk;

		cout << "^^        WELCOME TO YOUR PARTITION FIREST TIME         ^^" << endl;
		cout << "Please enter name for your partition :";
		string s;
		cin >> s;
		MyDisk.name = s;
		cout << "Your partition name is " << s << endl;
		cout << "Now you have 0 folders and 0 files " << endl;
		
	
	do {
			system("pause");
			system("CLS");
			cout << "^^        WELCOME TO YOUR PARTITION FIREST TIME         ^^" << endl;
			cout << "Your partition name : " << MyDisk.name << endl;
			cout << "Now you have " << MyDisk.folders.size() << " folders and " << MyDisk.files.size() << " files " << endl << endl;

			cout << "To create folder ,Please enter ^ 1 ^" << endl;
			cout << "To create file   ,Please enter ^ 2 ^" << endl;
			cout << "To display all content in this position    ,Please enter ^ 3 ^ " << endl;
			cout << "To delete file from this position          ,Please enter ^ 4 ^ " << endl;
			cout << "To delete folder from this position        ,Please enter ^ 5 ^ " << endl;
			cout << "To copy file from hard to your partition   ,Please enter ^ 6 ^ " << endl;
			cout << "To copy file from this partition to hard   ,Please enter ^ 7 ^ " << endl;
			int choise;
			cin >> choise;
				
		switch (choise)
			{
				case 1:
				{
					start_f:
					folder _New;
					cout << "the folder name is :";
					cin >> _New.name;

					//cheek about name
					bool cheek = false;
					for (int i = 0; i < MyDisk.folders.size(); i++)
					{
						if (MyDisk.folders[i].name == _New.name)
						{
								cheek = true;
									break;
						}
					}

					if (cheek == false) //the name is unique
					{
						cout << "if you need to create any files inside that ?(y/n) : ";
						char ch;
						cin >> ch;
						MyDisk.folders.push_back(_New);
						if (ch == 'y')
						{
							cout << "how meny files need to create ? ";
							int num;
							cin >> num;
							for (int i = 0; i < num; i++)
							{
								start_ff:
								file _new;
								cout << "enter the file extention (like .txt | .jpg | .png |.mp4 ) : ";
								cin >> _new.extention;
								cout << "enter the file name : ";
								cin >> _new.name;
								
								//cheek about name
								bool cheek = false;
									for (int j = 0; j < MyDisk.folders[MyDisk.folders.size()-1].files_in_this_folder.size(); j++)
									{
										if (
											(_new.name == MyDisk.folders[MyDisk.folders.size() - 1].files_in_this_folder[j].name) &&
											(_new.extention == MyDisk.folders[MyDisk.folders.size() - 1].files_in_this_folder[j].extention)
										   )
										{
											   cheek = true;
											break;
										}
									}
							
						
								if (cheek == false) //the name is unique
								{
									MyDisk.folders[MyDisk.folders.size() - 1].files_in_this_folder.push_back(_new);
									cout << "*************************************************************" << endl;
								}
								else
								{
									cout << "this name is already exist ,please try agin ^^" << endl;
									goto start_ff;
								}
						

							}

						}

				
					}
					else //name is already exist
					{
						cout << "this name is already exist ,please try agin ^^" << endl;
						goto start_f;

					}
			
			
					break;
				}
				case 2: 
				{

					cout << "how meny files need to create ? ";
					int num;
					cin >> num;
					for (int i = 0; i < num; i++)
					{
						retry:
						file _new;
						cout << "enter the file extention (like .txt | .jpg | .png | .mp4 ) : ";
						cin >> _new.extention;
						cout << "enter the file name : ";
						cin >> _new.name;
						bool cheek=false;
						for (int i = 0; i < MyDisk.files.size(); i++) 
						{
							if ( _new.name == MyDisk.files[i].name && _new.extention==MyDisk.files[i].extention )
							{
								cheek = true;
								break;
							}
						}
						if (cheek == false) 
						{
							MyDisk.files.push_back(_new);
							cout << "*************************************************************" << endl;
						}
						else //name is already exist
						{
							cout << "this name is already exist ,please try agin ^^" << endl;
							goto retry;

						}
				
					}
					break;
				}
				case 3:
				{
					cout << "you have " << MyDisk.files.size() << " files" << endl;

					for (int i = 0; i < MyDisk.files.size(); i++) {
						file current;
						current = MyDisk.files[i];
						cout << "the file name : " << current.name << current.extention << endl;
						cout << "the file size : " << current.size << endl;
						cout << "******************************************************" << endl;
					}

					cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl << endl;

					cout << "you have " << MyDisk.folders.size() << " folders" << endl;

					for (int i = 0; i < MyDisk.folders.size(); i++) {
						folder current;
						current = MyDisk.folders[i];

						cout << "the folder name : " << current.name << endl;
						cout << "the files inside this folder :" << endl;
						for (int j = 0; j < current.files_in_this_folder.size(); j++)
						{
							cout << "the file name :" << current.files_in_this_folder[j].name << current.files_in_this_folder[j].extention << endl;
							cout << "the file size : " << current.files_in_this_folder[j].size << endl;
							cout << "---------------------------------------------------" << endl << endl;
						}
						cout << "***************************************************" << endl;
					}

					break;
				}
				case 4:
				{
					repath_de:
					cout << "please, enter the file path do you want to delete in this partition :";
					string path_part;
					cin >> path_part;
					bool cheak = false;
					string name_folder = "";
					string name_file = "";
					file current_file_part;
					folder current_folder_part;
					bool ch_part_path_fol = false;
					bool ch_part_path_fil = false;
					int count_fo = -1;
					int count_fi = -1;

					for (int i = 0; i < path_part.length(); i++)
						if (path_part[i] == '\\')
							cheak = true;
					
					if (cheak == true)
					{
						for (int i = 0; i < path_part.length(); i++) 
						{
							if (path_part[i] != '\\')
								name_folder += path_part[i];
							else
								break;
						}

						for (int i = 0; i < MyDisk.folders.size(); i++)
						{
							if (MyDisk.folders[i].name == name_folder)
							{
								ch_part_path_fol = true;
								count_fo = i;
								current_folder_part = MyDisk.folders[i];
							}
						}


						for (int i = name_folder.length() + 1; i < path_part.length(); i++)
						{
							if (path_part[i] != '.')
								name_file += path_part[i];
							else
								break;
						}

						string ex = "";
						for (int i = path_part.length() - 1; i > 0; i--)
							if (path_part[i] != '.')
								ex += path_part[i];
							else
								break;
						ex += '.';
						reverse(ex.begin(), ex.end());

						for (int i = 0; i < current_folder_part.files_in_this_folder.size(); i++) 
						{
							if (current_folder_part.files_in_this_folder[i].name == name_file &&
								current_folder_part.files_in_this_folder[i].extention == ex)
							{
								ch_part_path_fil = true;
								count_fi = i;
								current_file_part = current_folder_part.files_in_this_folder[i];
							}
						}

					}
					else
					{
						for (int i = 0; i < path_part.length(); i++) 
						{
							if (path_part[i] != '.')
								name_file += path_part[i];
							else
								break;
						}

						string ex = "";
						for (int i = path_part.length() - 1; i > 0; i--)
							if (path_part[i] != '.')
								ex += path_part[i];
							else
								break;
						ex += '.';
						reverse(ex.begin(), ex.end());

						for (int i = 0; i < MyDisk.files.size(); i++)
						{
							if (MyDisk.files[i].name == name_file && MyDisk.files[i].extention == ex)
							{
								ch_part_path_fil = true;
								count_fi = i;
								current_file_part = MyDisk.files[i];
							}
						}
					}
					if (!((cheak && ch_part_path_fil && ch_part_path_fol) || (ch_part_path_fil)))
					{
						cout << "the file not found at this path ,please write the correct path ^^" << endl;
						goto repath_de;
					}
					if (count_fo > -1 && count_fi > -1) {
						MyDisk.folders[count_fo].files_in_this_folder.erase(MyDisk.folders[count_fo].files_in_this_folder.begin() + count_fi);
					}
					if (count_fo == -1 && count_fi > -1) {
						MyDisk.files.erase(MyDisk.files.begin() + count_fi);
					}

					cout << "^^             DONE             ^^" << endl;
					break;
				}
				case 5: 
				{
					
				re_f:
					cout << "please enter the folder name that you want to delete it :";
					string name;
					cin >> name;
					bool cheek = false;
					for (int i = 0; i < MyDisk.folders.size(); i++) 
					{
						if (MyDisk.folders[i].name == name) 
						{
							MyDisk.folders.erase(MyDisk.folders.begin() + i);
							cheek = true;
							break;
						}
						
					}
					if (cheek == false)
					{
						cout << "this folder not found ,please try again^^" << endl;
						goto re_f;
					}
					cout << "^^            DONE                ^^" << endl;
					break;
				}
				case 6:
				{
					repath:
					file asd;
					streampos begin, end;
					char*file_data;
					long fsize;

					cout << "enter the file path at hard :";
					string path;
					cin >> path;

					fstream f(path, ios::in | ios::binary);

					if (f.is_open())
					{
						//file size
						begin = f.tellg();
						f.seekg(0, ios::end);
						end = f.tellg();
						asd.size = (end - begin);
				
						//file data
						f.seekg(0, ios::beg);
						file_data = new  char[asd.size];
						asd.content = new  char[asd.size];
						f.read(file_data, asd.size);
						asd.content = file_data;

						f.close();
				
						//file extention
						string ex = "";
						for (int i = path.length() - 1; i > 0; i--)
							if (path[i] != '.')
								ex += path[i];
							else
								break;

						//file name
						string name = "";
						for (int i = path.length() - ex.length() - 2; i > 0; i--) {
							if (path[i] != '\\')
								name += path[i];
							else
								break;
						}

						ex += '.';
						reverse(ex.begin(), ex.end());
						asd.extention = ex;

						reverse(name.begin(), name.end());
						asd.name = name;


						cout << "Do you want to copy it in a folder?(y/n) :";
						char ch;
						cin >> ch;

						start:
						if (ch == 'y')
						{
							folder _New;
							cout << "the folder name is :";
							cin >> _New.name;

							//cheek about name
							bool cheek = false;
							for (int i = 0; i < MyDisk.folders.size(); i++) {
								if (MyDisk.folders[i].name == _New.name)
								{
									cheek = true; break;
								}
							}

							if (cheek == false) //the name is unique
							{
								_New.files_in_this_folder.push_back(asd);
								MyDisk.folders.push_back(_New);
								cout << "your file copyed at path " << MyDisk.name << ":\\" << _New.name << endl;
							}
							else
							{
								cout << "this name is already exist ,please try agin ^^" << endl;
								goto start;
							}
						}
						else
						{
							MyDisk.files.push_back(asd);
							cout << "your file copyed at path " << MyDisk.name << ":\\" << endl;
						}


						cout << "       DONE         " << endl;
					}
					else {
						cout << "the file not found at this path ,please write the correct path ^^" << endl;
						goto repath;
					}

					break;
				}
				case 7:
				{
					repath_part:
					cout << "please, enter the file path in this partition :";
					string path_part;
					bool cheak = false;
					cin >> path_part;
					file current_file_part;
					folder current_folder_part;
					string name_folder = "";
					string name_file = "";
					bool ch_part_path_fol = false;
					bool ch_part_path_fil = false;

					for (int i = 0; i < path_part.length(); i++)
						if (path_part[i] == '\\')
							cheak = true;
				
					if (cheak == true) 
					{
						for (int i = 0; i < path_part.length(); i++) {
							if (path_part[i] != '\\')
								name_folder += path_part[i];
							else
								break;
						}
				
				
						for (int i = 0; i < MyDisk.folders.size(); i++) {
							if (MyDisk.folders[i].name == name_folder)
							{
								ch_part_path_fol = true;
								current_folder_part = MyDisk.folders[i];
							}
						}
						for (int i = name_folder.length() + 1; i < path_part.length(); i++) {
							if (path_part[i] != '.')
								name_file += path_part[i];
							else
								break;
						}
						string ex = "";
						for (int i = path_part.length() - 1; i > 0; i--)
							if (path_part[i] != '.')
								ex += path_part[i];
							else
								break;
						ex += '.';
						reverse(ex.begin(), ex.end());
				
						for (int i = 0; i < current_folder_part.files_in_this_folder.size(); i++) {
							if ( current_folder_part.files_in_this_folder[i].name == name_file &&
								current_folder_part.files_in_this_folder[i].extention == ex )
							{
								ch_part_path_fil = true;
								current_file_part = current_folder_part.files_in_this_folder[i];
							}
						}
					}
					else 
					{
						for (int i = 0; i < path_part.length(); i++)
						{
							if (path_part[i] != '.')
								name_file += path_part[i];
							else
								break;
						}

						string ex = "";
						for (int i = path_part.length() - 1; i > 0; i--)
							if (path_part[i] != '.')
								ex += path_part[i];
							else
								break;

						ex += '.';
						reverse(ex.begin(), ex.end());
						for (int i = 0; i < MyDisk.files.size(); i++)
							if (MyDisk.files[i].name == name_file && MyDisk.files[i].extention == ex)
							{
								ch_part_path_fil = true;
								current_file_part = MyDisk.files[i];
							}

					}
					if (! ( (cheak && ch_part_path_fil && ch_part_path_fol) || (ch_part_path_fil)) )
					{
						cout << "the file not found at this path ,please write the correct path ^^" << endl;
						goto repath_part;
					}

					repath_w:
					cout << "please, enter the path that you want to copy to in hard :" << endl;
					string path_hard;
					cin >> path_hard;

					path_hard += current_file_part.name + current_file_part.extention;
			
					fstream f(path_hard, ios::out | ios::binary);
					if (f.is_open())
					{
						f.write(current_file_part.content, current_file_part.size);
						f.close();


						cout << "       DONE         " << endl;
					}
					else {
						cout << "the file not found at this path ,please write the correct path ^^" << endl;
						goto repath_w;
					}
					break;
				}
				default:
				 {
					cout << " ^^  INVALID CHOICE   ^^" << endl;
					break; 
		
				 }
			}

		} while (true);
		
	
	system("pause");
	return 0;
}
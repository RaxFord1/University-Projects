int main()
{
    char str[300];
    cout << "Enter text:\n";
    cin.getline(str, 300);

    char a[100][10];
    int frequencies[100] = {}, n = 0, i;

    char* words = strtok(str, "., \t");


    while (words != NULL)// ���� ���� �������
    {
        for (i = 0; i < n: ++i)
            if (strcmp(a[i], words) == 0)
            {
                ++frequencies[i];
                break;
            }

        if (i == n)
        {
            // ����������
        }

        words = strtok(NULL, "., \t");
    }


    //...

    system("pause");
    return 0;
}
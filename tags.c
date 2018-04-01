#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DEFAULT_TAGS_HOME = "/"
#define DEFAULT_TAGS_DIR = ".tags"

int usage()
{
    printf("Command not specified. \n"
           "tags <option> <arguments> \n"
           "Options: \n"
           "    add <filepath> <tagname>        - Add a new tag to file \n"
           "    remove <filepath> <tagname>     - Remove a tag from file \n"
           "    addtag <tagname>                - Create a new tag \n"
           "    removetag <tagname>             - Delete a tag \n"
           "    list                            - List all tags or list for a file \n"
           "    search <tagname>                - Search all files with a tag name \n");
    return 0;
}

char *get_tags_dir()
{

    struct passwd *pws;
    pws = getpwuid(geteuid());

    printf("username: %s \n", pws->pw_name);

    char *dir = (char *)malloc(30 * sizeof(char));

    printf("-------------1--------\n");
    strcpy(dir, "/home/");
    strcat(dir, pws->pw_name);
    printf("-------------2--------\n");
    strcat(dir, "/.tags");
    printf("-------------3--------\n");

    struct stat st = {0};
    printf("-------------4--------\n");

    if (stat(dir, &st) == -1)
    {
        printf("-------------5--------\n");

        int check = mkdir(dir, 0700);
        if (check == 0)
        {
            printf("work\n");
        }
        else
        {
            printf("not work\n");
        }
    }
    else
    {
        printf("dir already exist\n");
    }

    return dir;
}

int get_tag_dir() {}

void check_creat_base_folder()
{
    char *dir = get_tags_dir();
    free(dir);
}
int get_linked_file_name() {}

int creat_tag() {}

int delete_tag() {}

int tag_file() {}

int tag_exists() {}

int create_random_string() {}

int search_tag() {}

int list_tags() {}

int remove_tag() {}

int main(int argc, char *argv[])
{
    // system("dir");
    check_creat_base_folder();
    if (argc == 1)
    {
        usage();
        return 0;
    }

    if (strcmp(argv[1], "add") == 0)
    {
        printf("add \n");
    }
    else if (strcmp(argv[1], "remove") == 0)
    {
        printf("remove \n");
    }
    else if (strcmp(argv[1], "addtag") == 0)
    {
        printf("addtag \n");
    }
    else if (strcmp(argv[1], "removetag") == 0)
    {
        printf("removetag \n");
    }
    else if (strcmp(argv[1], "search") == 0)
    {
        printf("search \n");
    }
    else if (strcmp(argv[1], "list") == 0)
    {
        printf("list \n");
    }
    else if (strcmp(argv[1], "help") == 0)
    {
        printf("help \n");
    }
    else
    {
        usage();
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        fprintf(stdout, "Current working dir: %s\n", cwd);
    else
        perror("getcwd() error");

    return 0;
}
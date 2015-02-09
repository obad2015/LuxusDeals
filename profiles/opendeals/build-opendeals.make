; Use this file to build a full distribution including Drupal core and the
; Opendeals install profile using the following command:
;
; drush make distro.make <target directory>

api = 2
core = 7.15

includes[] = drupal-org-core.make

; Add Opendeals to the full distribution build.
projects[opendeals][type] = profile
projects[opendeals][version] = 1.x-dev
projects[opendeals][download][type] = git
projects[opendeals][download][url] = http://git.drupal.org/project/opendeals.git
projects[opendeals][download][branch] = 7.x-1.x
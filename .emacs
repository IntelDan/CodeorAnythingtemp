(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-safe-themes (quote ("929744da373c859c0f07325bc9c8d5cc30d418468c2ecb3a4f6cb2e3728d4775" "943bff6eada8e1796f8192a7124c1129d6ff9fbd1a0aed7b57ad2bf14201fdd4" "31772cd378fd8267d6427cec2d02d599eee14a1b60e9b2b894dd5487bd30978e" "8016855a07f289a6b2deb248e192633dca0165f07ee5d51f9ba982ec2c36797d" "af4cfe7f2de40f19e0798d46057aae0bccfbc87a85a2d4100339eaf91a1f202a" "a405a0c2ec845e34ecb32a83f477ca36d1858b976f028694e0ee7ff4af33e400" "a1493957ee779057acdc4c337133f217dd7b2edfdeeffed903ba2f16246f665a" "6c57adb4d3da69cfb559e103e555905c9eec48616104e217502d0a372e63dcea" default)))
 '(inhibit-startup-screen t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

;;(require 'window-)
(winner-mode 1)
;;look up C library function
(global-set-key '[f3]' man)

;;copy and add by lp
(display-time-mode 1);显示时间，格式如下
(setq display-time-24hr-format t)
(setq display-time-day-and-date t)

(load-theme 'zenburn t);;load molokai theme

(setq toggle-full-screen t)

(scroll-bar-mode -1)
;;(tool-bar-mode -1)

;;set this to save bookmake, otherwise the bookmarks will lost after restart emacs
(setq bookmark-save-flag 1)

;;enable ido-mode
(require 'ido)
(ido-mode t)

(global-set-key '[f5]' compile);;M-x compile
(setq gdb-many-windows t) ;;使能gdb的多个窗口，这样在调试的时候就会出现多个窗口

(setq backup-directory-alist (quote(("."."~/.backup"))));;storing the backup file 


;;plugin:auto-complete
(add-to-list 'load-path "~/.emacs.d")
(require 'auto-complete-config)
;;(require 'auto-complete-yasnippet)
;;(require 'auto-complete-c)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/ac-dict")

(ac-config-default)
;(setq ac-source-yasnippet nil)


(require 'yasnippet "~/.emacs.d/plugins/yasnippet/yasnippet.el")
;;the snippet key of if is changed from cc-modeif to if in cc-mode
;;what the fuck why it is used as cc-mode.it almost waste the time of sleep
(setq yas/root-directory "/home/dvr/.emacs.d/plugins/yasnippet/snippets")
(yas/load-directory yas/root-directory)
(yas-global-mode 1)

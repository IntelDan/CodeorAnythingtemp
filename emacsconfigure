(require 'package)
(add-to-list 'package-archives '("org" . "http://orgmode.org/elpa/") t)
;this is the emacs config file
(add-to-list 'load-path "/usr/share/emacs/site-lisp/w3m")
(require 'w3m-load)
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(ansi-color-names-vector
   ["black" "red" "green" "yellow" "blue" "magenta" "cyan" "yellow"])
 '(background-color nil)
 '(background-mode dark)
 '(cursor-color nil)
 '(custom-safe-themes
   (quote
    ("fc5fcb6f1f1c1bc01305694c59a1a861b008c534cae8d0e48e4d5e81ad718bc6" default)))
 '(display-time-mode t)
 '(ecb-options-version "2.40")
 '(foreground-color nil)
 '(inhibit-default-init t)
 '(initial-scratch-message "")
 '(org-mobile-checksum-binary "/usr/bin/sha1sum")
 '(send-mail-function (quote smtpmail-send-it)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Monaco" :foundry "unknown" :slant normal :weight normal :height 98 :width normal))))
 '(font-lock-string-face ((t (:foreground "cyan" :inverse-video nil :underline nil :slant normal :weight normal)))))

;;copy and add by lp
(display-time-mode 1);显示时间，格式如下
(setq display-time-24hr-format t)
(setq display-time-day-and-date t)

;;配色方案
;;(load-theme 'solarized-[light|dark] t)
;;(load-file "~/emacs-color-theme-solarized/color-theme-solarized.el")
;;(require 'color-theme)
;;(color-theme-initialize)

(add-to-list 'load-path "~/emacs-color-theme-solarized" t)
(require 'color-theme-solarized)
(load-theme 'solarized-dark t)
;;(color-theme-Solarized Dark)
;;(add-hook 'c-mode-common-hook 'color-theme-taylor)
;;(add-hook 'c++-mode-common-hook 'color-theme-taylor)

;;added for the org-mod
(require 'package)
(add-to-list 'package-archives '("org" . "http://orgmode.org/elpa/") t)

;;org-mobile config
(setq org-mobile-directory "~/Ubuntu One/org")
;;(org-mobile-checksum-binary "/usr/bin/sha1sum")这是正确设置的方法
(setq org-directory "~/org")
(setq org-mobile-inbox-for-pull "~/org/testfor.org")
(setq org-mobile-inbox-for-pull "~/Ubuntu One/org/mobileorg.org")

(global-set-key '[f3]' man) ;;查看C函数man的快捷键
(global-set-key '[f5]' compile);;M-x compile

(setq x-select-enable-clipboard t) ;;让emacs支持外部程序的拷贝和粘帖

(setq gdb-many-windows t) ;;使能gdb的多个窗口，这样在调试的时候就会出现多个窗口

;;设置org-mode的提醒，默认是不带提醒功能的
;;begin
(defun wl-org-agenda-to-appt ()
  ;;Dangerous!!!,This might the entries added by 'appt-add' manualy.
  (org-agenda-to-appt t "TODO"))
(wl-org-agenda-to-appt)
(defadvice  org-agenda-redo (after org-agenda-redo-add-appts)
  "Pressing `r' on the agenda will also add appointments."
  (progn
    (let ((config (current-window-configuration)))
      (appt-check t)
      (set-window-configuration config))
    (wl-org-agenda-to-appt)))

(ad-activate 'org-agenda-redo)
;;在 Org Mode 的 Agenda View 下，按 r 或者 g ，就可以把有具体时间的任务添加到appt的任务提醒列表里面。需要注意的是，手工使用 appt-add 添加的提醒将被清除，无法恢复。所以，当使用本节的配置时，请将任务添加到相应的org文件里，而不是使用 appt-add 。
;;end
  
;;add filecache----However, note that the C-<tab> character cannot be typed on most text terminals.
;;在终端下不能使用，只能用在图形界面下
(require 'filecache)
(file-cache-add-directory-recursively "~/Documents")

;;auto complete
(require 'auto-complete-config)
(ac-config-default)

;;切换回C-x 1最大化前的分割窗口状态，快捷键：C-c <left>
(when (fboundp 'winner-mode) (winner-mode) (windmove-default-keybindings))

;;added for cscope
(require 'xcscope)
(add-hook 'c-mode-common-hook
	  '(lambda ()
	     (require 'xcscope))) ;;added for loading in the c or cpp file
;;added for the search speed
(setq cscope-do-not-update-database t)

;;enable  CEDET- enable the CEDET tools which were merged with Emacs
(require 'cedet)
(global-ede-mode 1)
(require 'semantic/sb)
(semantic-mode 1)
(require 'semantic/analyze)
(provide 'semantic-analyze)
(provide 'semantic-ctxt)
(provide 'semanticdb)
(provide 'semanticdb-find)
(provide 'semanticdb-mode)
(provide 'semantic-load)

;;load ecb
(add-to-list 'load-path
	     "/home/liup/Downloads/ecb-2.40")
(require 'ecb)
(require 'ecb-autoloads)
;;(require 'ecb-winman-support)
;;(ecb-winman-enable-support)
;;下面这行防止报错
(setq stack-trace-on-error t)
;;(setq ecb-fix-window-size t)
;;(ecb-activate)
;;配置ECB帮助
;;~/.emacs.d/ecb/info-help 为ecb安装目录下帮助文件夹
(setq Info-default-directory-list
      (append  Info-default-directory-list
	       '("~/Downloads/ecb-2.40/info-help")))

;;ecb-auto-activate必须在setq stack-trace-on-error t 后面
;;自动启动ecb，并且不显示每日提示
;;(setq ecb-auto-activate t ecb-tip-of-the-day nil)

;;###代码折叠功能:系统自带###########
(load-library "hideshow") ;;开启代码折叠功能
(add-hook 'c-mode-hook 'hs-minor-mode)   ;;C文件折叠功能
(add-hook 'c++-mode-hook 'hs-minor-mode)   ;;C++文件折叠功能
(add-hook 'python-mode-hook 'hs-minor-mode);;Python文件折叠功能
(add-hook 'javscript-mode-hook 'hs-minor-mode);;Javascript文件折叠功能
;;下面是一些代码绑定，由于C--是放大缩小的快捷键，而且F6-F9暂时没有定义
;;就先用这四个键
(global-set-key '[f6]'  hs-hide-block) ;;折叠代码
(global-set-key '[f7]'  hs-show-block) ;;显示背折叠代码
(global-set-key '[f8]'  hs-hide-all) ;;折叠所有代码
(global-set-key '[f9]'  hs-show-all) ;;显示所有折叠代码
;;但是这里最后两个快捷键，好像不是想要的效果

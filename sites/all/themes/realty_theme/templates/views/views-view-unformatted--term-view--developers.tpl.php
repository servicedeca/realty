<div class="container fin">
    <div class="col-xs-12 breadcrumb-block  margine-top">
        <ol class="breadcrumb zero-padding breadcrumbfix">
            <li><?php print $city; ?></li>
            <li class="active"><?php print $developers_link; ?></li>
        </ol>
    </div>
</div>

<div class="container fin margin-bottom">
    <?php foreach($developers as $value):?>
        <a href='<?php print $value['developer_link'];?>' class="col-xs-4 developer-item zero-paddiing">
            <?php print render($value['logo']); ?>
            <div class="develop-item-line">
            </div>
            <div class="developer-item-body" >
                <h3><?php print render($value['name']); ?></h3>
                <div class="develop-item-pblock">
                    <?php foreach($value['complexes'] as $val):?>
                        <p><?php print render($val['complex']); ?></p>
                    <?php endforeach;?>
                    <p class="develop-sum">
                        <?php print t('And other objects') ?>
                    </p>
                </div>
            </div>
        </a>
    <?php endforeach;?>
</div>